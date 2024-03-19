/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:31:08 by wchen             #+#    #+#             */
/*   Updated: 2024/03/19 21:52:17 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	skip_space(char *line, bool inverse)
{
	size_t	i;

	i = 0;
	while (line[i] == ' ' || (inverse && line[i] != '\0'))
		i++;
	if (!inverse)
		return (i);
	while (i > 0 && line[i - 1] == ' ')
		i --;
	return (i - 1);
}

static bool	top_bottom_judge(char *line)
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

static bool	front_back_judge(char *line)
{
	size_t	front;
	size_t	back;

	front = skip_space(line, false);
	if (front == ft_strlen(line))
		return (false);
	if (line[front] != '1')
		return (true);
	back = skip_space(line, true);
	if (line[back] != '1')
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
