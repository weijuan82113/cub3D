/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:59:46 by wchen             #+#    #+#             */
/*   Updated: 2023/11/02 20:43:55 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color_node	*ft_new_colorlst(char *obj, char *rgb)
{
	t_color_node	*color;

	color = malloc(sizeof(t_color_node));
	if (!color)
		return (NULL);
	color->obj = ft_cut_tr(obj);
	if (!color->obj)
		return (NULL);
	color->rgb = ft_cut_tr(rgb);
	if (!color->rgb)
		return (NULL);
	color->rgb_int = rgb_atoi(rgb);
	if (color->rgb_int < 0)
		return (NULL);
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
	if (check_rgb(split[1]))
		return (ft_error(COLOR_INPUT_ERR));
	if (!mlx->g->color_lst)
		mlx->g->color_lst = ft_new_colorlst(split[0], split[1]);
	else
		return (ft_colorlstadd_back(&(mlx->g->color_lst),
				ft_new_colorlst(split[0], split[1])));
	if (!mlx->g->color_lst)
		return (ft_error(COLOR_INITIAL_ERR));
	return (false);
}
