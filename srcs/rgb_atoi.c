/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:18:08 by wchen             #+#    #+#             */
/*   Updated: 2024/02/12 21:30:11 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_count(int rgb_int, int index)
{
	int	i;
	int	ret_num;

	i = 0;
	ret_num = rgb_int;
	while (i < 2 - index)
	{
		ret_num *= 256;
		i++;
	}
	return (ret_num);
}

int	rgb_atoi(char *rgb)
{
	char	**rgb_split;
	int		i;
	int		rgb_int;
	int		ret_num;

	rgb_split = ft_split(rgb, ',');
	i = 0;
	rgb_int = 0;
	ret_num = 0;
	if (!rgb_split)
		return (-1);
	while (rgb_split[i])
	{
		rgb_int = ft_atoi(rgb_split[i]);
		if (0 <= rgb_int && rgb_int < 256 && i <= 2)
			ret_num += rgb_count(rgb_int, i);
		else
		{
			free_split(rgb_split);
			return (-1);
		}
		i++;
	}
	free_split(rgb_split);
	return (ret_num);
}
