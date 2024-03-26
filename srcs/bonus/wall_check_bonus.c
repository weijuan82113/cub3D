/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:31:08 by wchen             #+#    #+#             */
/*   Updated: 2024/03/19 23:00:08 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_movable_area(char area)
{
	if (area == ' ' || area == '1')
		return (false);
	return (true);
}

static bool	top_bottom_judge(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_movable_area(line[i]))
			return (true);
		i++;
	}
	return (false);
}

static bool	front_back_judge(char *line)
{
	size_t	length;

	length = ft_strlen(line);
	if (length == 0)
		return (false);
	if (is_movable_area(line[0]))
		return (true);
	if (is_movable_area(line[length - 1]))
		return (true);
	return (false);
}

bool	wall_check(char **map, int h)
{
	int	i;

	i = 0;
	while (map[i])
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
