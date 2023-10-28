/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:59:46 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 17:24:03 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color_node	*ft_new_colorlst(char *obj, char *rbg)
{
	t_color_node	*color;

	if (!(color = malloc(sizeof(t_color_node))))
		return (NULL);
	color->obj = ft_cut_tr(obj);
	color->rbg = ft_cut_tr(rbg);
	return (color);
}

bool ft_colorlstadd_back(t_color_node **head, t_color_node *new)
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

bool add_color_lst(t_mlx *mlx, char** split)
{
	if (!mlx->g->color_lst)
		mlx->g->color_lst = ft_new_colorlst(split[0], split[1]);
	else
		return (ft_colorlstadd_back(&(mlx->g->color_lst), ft_new_colorlst(split[0], split[1])));
	if (!mlx->g->color_lst)
		return (ft_error(MALLOC_ERR));
	return (false);
}