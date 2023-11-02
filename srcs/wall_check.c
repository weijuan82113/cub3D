/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:31:08 by wchen             #+#    #+#             */
/*   Updated: 2023/11/01 21:59:02 by wchen            ###   ########.fr       */
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
	if (line[str_len - 1] == '\n')
		return (line[str_len - 2] != '1');
	return (line[str_len - 1] != '1');
}

bool	wall_check(t_node *line_lst, int h)
{
	int		i;
	t_node	*temp_node;

	i = 0;
	temp_node = line_lst;
	while (temp_node)
	{
		if (i == 0 || (i + 1) == h)
		{
			if (top_bottom_judge(temp_node->content))
				return (true);
		}
		else if (front_back_judge(temp_node->content))
			return (true);
		temp_node = temp_node->next;
		i++;
	}
	return (false);
}
