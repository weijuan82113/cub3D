/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:06:25 by wchen             #+#    #+#             */
/*   Updated: 2023/10/10 22:35:10 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool extension_check(char *file_name)
{
	char	*ext;
	char	*ber;

	ber = ".cub";
	ext = ft_strrchr(file_name, '.');
	if (ext == NULL)
		return (true);
	while (*ext != '\0' && *ber != '\0')
	{
		if (*(ext) != *ber)
			return (true);
		ext++;
		ber++;
	}
	if (*ext != '\0' || *ber != '\0')
		return (true);
	return (false);
}

bool incorrect_identify(char* s, char* compare)
{
	int i;
	char **identifier_array;
	int	identifier_num;

	identifier_array = ft_split(compare, '/');
	identifier_num = 0;
	while (identifier_array[identifier_num])
		identifier_num++;
	i = 0;
	while(i < identifier_num)
	{
		if (ft_strncmp(s, identifier_array[i], ft_strlen(identifier_array[i])) == 0)
			return (false);
		i ++;
	}
	return(true);
}


t_img	*ft_new_idlst(char *obj, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return NULL;
	img->obj = obj;
	img->img_path = path;
	img->next = NULL;
	return (img);
}

bool ft_idlstadd_back(t_img **head, t_img *new)
{
	t_img	*tail;

	if (!head || !new)
		return (ft_error(MALLOC_ERR));
	else if (!*head)
		*head = new;
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new;
	}
	return (false);
}

bool add_id_lst(t_g_board *g_board, char** split)
{
	if (!g_board->img_lst)
		g_board->img_lst = ft_new_idlst(split[0], split[1]);
	else
		return (ft_idlstadd_back(&(g_board->img_lst), ft_new_idlst(split[0], split[1])));
	if (!g_board->img_lst)
		return (ft_error(MALLOC_ERR));
	return (false);
}

bool check_identifier(t_g_board *g_board, char *line)
{
	char **split_result;
	split_result = ft_split(line, ' ');
	if (incorrect_identify(split_result[0], IDENTIFIER))
		return (ft_error(IDENTIFIER_TYPE_ERR));
	return (add_id_lst(g_board,split_result));
}

void debug_print_imglst(t_g_board *g_board)
{
	t_img	*temp_img;

	temp_img = g_board->img_lst;
	while (temp_img)
	{
		printf("print obj:%s\n", temp_img->obj);
		printf("print img_path:%s\n", temp_img->img_path);
		temp_img = temp_img->next;
	}
}

void debug_print_linelst(t_g_board *g_board)
{
	t_node	*temp_line;

	temp_line = g_board->line_lst;
	while (temp_line)
	{
		printf("print line content:%s\n", (char *)temp_line->content);
		temp_line = temp_line->next;
	}
	printf("map h is %d\n", g_board->m_info->h);
	printf("map w is %d\n", g_board->m_info->w);
}

void save_line_lst(t_g_board *g_board,char *line)
{
	int str_len;

	str_len = 0;
	str_len = ft_strlen(line);
	if (str_len > g_board->m_info->w)
		g_board->m_info->w = str_len;
	if (!g_board->line_lst)
		g_board->line_lst = ft_lstnew(line);
	else
		ft_lstadd_back(&g_board->line_lst, ft_lstnew(line));
}

bool incorrect_character(char c,char **split)
{
	int i;

	i = 0;
	while(split[i] && c != '\n')
	{
		printf("c %c\n", c);
		printf("character split %c\n", *split[i]);
		if (c == *split[i])
			return (false);
		i ++;
	}
	if (c == '\n')
		return (false);
	return (true);
}

bool character_judge(char *line)
{
	int i;
	char **split;

	i = 0;
	split = ft_split(CHARACTER, '/');
	while (line[i])
	{
		if (incorrect_character(line[i], split))
		{
			free (split);
			return (ft_error(CHARACTER_ERR));
		}
		i ++;
	}
	free(split);
	return (false);
}

bool line_judge(t_g_board *g_board, char *line)
{
	if (g_board->m_info->h != 0 && ft_isstrempty(line) == 1)
		return (ft_error(INPUT_EMPTY_LINE_ERR));
	if (ft_isstrempty(line) == 0)
	{
		if (character_judge(line))
			return (true);
		save_line_lst(g_board, line);
		g_board->m_info->h ++;
	}
	return (false);
}

bool identifier_judge(t_g_board *g_board, char *line)
{
	if (check_identifier(g_board, line))
		return (true);
	g_board->t_count ++;
	return (false);
}

bool line_check(char* line, t_g_board *g_board)
{
	printf("t_count:%d\n", g_board->t_count);
	printf("ft_isstrempty:%d\n", ft_isstrempty(line));
	if (g_board->t_count < 6 && ft_isstrempty(line) == 0)
		return (identifier_judge(g_board, line));
	else if (g_board->t_count == 6)
		return (line_judge(g_board, line));
	return (false);
}

void game_board_initial(t_g_board *g_board)
{
	g_board->x = 0;
	g_board->y = 0;
	g_board->t_count = 0;
	g_board->line_lst = NULL;
	g_board->img_lst = NULL;
	g_board->m_info = malloc(sizeof(t_map_info *));
	g_board->m_info->h = 0;
	g_board->m_info->w = 0;
}

bool create_map_array(t_g_board *g_board)
{
	if(g_board->m_info->h < 3 || g_board->m_info->w < 3)
		return (ft_error(MAP_SIZE_ERR));
	return (false);
}

bool file_context_check(int fd)
{
	char		*line;
	int			index;
	t_g_board	*g_board;

	line = NULL;
	index = 0;
	g_board = malloc(sizeof(*g_board));
	if (!g_board)
		return (true);
	game_board_initial(g_board);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line_check(line, g_board))
			return (true);
		//printf("%s",line);
		index ++;
	}
	debug_print_imglst(g_board);
	debug_print_linelst(g_board);
	if (create_map_array(g_board))
		return (true);
	return (false);
}

bool file_check(char *file_path)
{
	int fd;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_error(OPEN_FILE_ERR));
	if (file_context_check(fd))
		return (true);
	return (false);
}

bool validation(int argc, char**argv)
{
	(void) argv;
	if (argc != 2)
		return (ft_error(ARG_ERR));
	if (extension_check(argv[1]))
		return (ft_error(FILE_EXT_ERR));
	if (file_check(argv[1]))
		return (true);
	return (false);
}
