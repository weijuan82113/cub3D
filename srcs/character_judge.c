/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_judge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:12:24 by wchen             #+#    #+#             */
/*   Updated: 2023/11/07 22:15:22 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_chr	*character_judge_inital(char *line, int *x, int *y)
{
	t_chr	*chr;

	chr = malloc(sizeof(t_chr));
	errno = 0;
	chr->c_split = ft_split(CHARACTER, '/');
	chr->p_split = ft_split(PLAYER, '/');
	chr->line = line;
	chr->x = x;
	chr->y = y;
	return (chr);
}

bool	check_character(t_g_board *g, t_chr *chr)
{
	int		i;
	bool	result;

	i = 0;
	result = false;
	while (chr->line[i])
	{
		if (incorrect_character(chr->line[i], chr->c_split))
		{
			result = ft_error(CHARACTER_ERR);
			break ;
		}
		if (is_player_character(chr->line[i], chr->p_split))
		{
			if (*chr->y != -1 || *chr->x != -1)
			{
				result = ft_error(PLAYER_DUPLICATION_ERR);
				break ;
			}
			*chr->y = *g->m_info->h;
			*chr->x = i;
		}
		i++;
	}
	return (result);
}

bool	character_judge(t_g_board *g, char *line, int *x, int *y)
{
	t_chr	*chr;
	bool	result;

	chr = character_judge_inital(line, x, y);
	if (!chr)
		return (ft_error(MALLOC_ERR));
	result = check_character(g, chr);
	free_split(chr->c_split);
	free_split(chr->p_split);
	free(chr);
	return (result);
}
