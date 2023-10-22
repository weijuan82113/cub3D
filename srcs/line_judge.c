/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_judge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:56:08 by wchen             #+#    #+#             */
/*   Updated: 2023/10/22 22:49:08 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void save_line_lst(t_g_board *g_board,char *line)
{
	int str_len;

	str_len = 0;
	str_len = ft_strlen(line);
	if (str_len > *g_board->m_info->w)
		*g_board->m_info->w = str_len;
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
	if (*g_board->m_info->h != 0 && ft_isstrempty(line) == 1)
		return (ft_error(INPUT_EMPTY_LINE_ERR));
	if (ft_isstrempty(line) == 0)
	{
		if (character_judge(line))
			return (true);
		save_line_lst(g_board, line);
		*g_board->m_info->h = *g_board->m_info->h + 1;
	}
	return (false);
}