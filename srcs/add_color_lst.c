/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:59:46 by wchen             #+#    #+#             */
/*   Updated: 2023/11/09 22:39:32 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color_node	*ft_new_colorlst(char *obj, int rgb)
{
	t_color_node	*color;

	color = malloc(sizeof(t_color_node));
	if (!color)
		return (NULL);
	color->obj = ft_cut_tr(obj);
	if (!color->obj)
	{
		free(color);
		return (NULL);
	}
	color->rgb_int = rgb;
	color->next = NULL;
	return (color);
}

bool	ft_colorlstadd_back(t_color_node **head, t_color_node *new)
{
	t_color_node	*tail;

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

bool	check_rgb(char *str)
{
	int	i;
	int	comma_num;

	i = 0;
	comma_num = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_num++;
		if (('0' <= str[i] && str[i] <= '9') || str[i] == ',' || str[i] == '\n')
			i++;
		else
			return (true);
	}
	if (comma_num != 2)
		return (true);
	return (false);
}

bool	add_color_lst(t_mlx *mlx, char **split)
{
	int	rgb;

	errno = 0;
	if (check_rgb(split[1]))
		return (ft_error(COLOR_INPUT_ERR));
	rgb = rgb_atoi(split[1]);
	if (rgb < 0)
		return (ft_error(COLOR_INPUT_ERR));
	if (!mlx->g->color_lst)
		mlx->g->color_lst = ft_new_colorlst(split[0], rgb);
	else
		return (ft_colorlstadd_back(&(mlx->g->color_lst),
				ft_new_colorlst(split[0], rgb)));
	if (!mlx->g->color_lst)
		return (ft_error(COLOR_INITIAL_ERR));
	return (false);
}
