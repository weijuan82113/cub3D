/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_judge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:56:08 by wchen             #+#    #+#             */
/*   Updated: 2023/11/04 12:16:32 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_line_lst(t_g_board *g_board, char *line)
{
	int	str_len;

	str_len = 0;
	str_len = ft_strlen_ntr(line);
	if (str_len > *g_board->m_info->w)
		*g_board->m_info->w = str_len;
	if (!g_board->line_lst)
		g_board->line_lst = ft_lstnew(line);
	else
		ft_lstadd_back(&g_board->line_lst, ft_lstnew(line));
}

bool	incorrect_character(char c, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (c == '\n' || c == *split[i])
			return (false);
		i++;
	}
	return (true);
}

bool	is_player_character(char c, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (c == *split[i])
			return (true);
		i++;
	}
	return (false);
}

bool	character_judge(t_g_board *g, char *line, int *x, int *y)
{
	int		i;
	char	**c_split;
	char	**p_split;
	bool	result;

	i = 0;
	c_split = ft_split(CHARACTER, '/');
	p_split = ft_split(PLAYER,- '/');
	result = false;
	errno = 0;
	while (line[i])
	{
		if (incorrect_character(line[i], c_split))
		{
			result = ft_error(CHARACTER_ERR);
			break;
		}
		if (is_player_character(line[i], p_split))
		{
			if (*y != -1 && *x != -1)
			{
				result = ft_error(PLAYER_DUPLICATION_ERR);
				break;
			}
			*y = *g->m_info->h;
			*x = i;
		}
		i++;
	}
	free_split(c_split);
	free_split(p_split);
	return (result);
}

bool	line_judge(t_g_board *g_board, char *line, int *x, int *y)
{
	char	*content;

	errno = 0;
	if (*g_board->m_info->h != 0 && ft_isstrempty(line) == 1)
		return (ft_error(INPUT_EMPTY_LINE_ERR));
	if (ft_isstrempty(line) == 0)
	{
		if (character_judge(g_board, line, x, y))
			return (true);
		content = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!content)
			return (ft_error(MALLOC_ERR));
		ft_memcpy(content, line, ft_strlen(line));
		save_line_lst(g_board, content);
		*g_board->m_info->h = *g_board->m_info->h + 1;
	}
	return (false);
}
