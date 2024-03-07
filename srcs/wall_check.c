/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:31:08 by wchen             #+#    #+#             */
/*   Updated: 2024/03/07 23:53:58 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

bool	top_bottom_judge(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			return (true);
		i++;
	}
	return (false);
}

bool	front_back_judge(char *line)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = 0;
	i = skip_space(line);
	if (line[i] != '1')
		return (true);
	str_len = ft_strlen(line);
	if (str_len != 0 && line[str_len - 1] == ' ')
		str_len --;
	return (line[str_len - 1] != '1');
}

bool	wall_check(char **map, int h)
{
	int		i;

	i = 0;
	while (map)
	{
		if (i == 0 || (i + 1) == h)
		{
			if (top_bottom_judge(map[i]))
				return (true);
		}
		else if (front_back_judge(map[i]))
			return (true);
		i++;
	}
	return (false);
}
