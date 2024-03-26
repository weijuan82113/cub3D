/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:08:32 by wchen             #+#    #+#             */
/*   Updated: 2024/02/12 21:53:32 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_imglstdelone(t_img_node *lst, void *p_mlx)
{
	if (!lst)
		return ;
	if (p_mlx)
		mlx_destroy_image(p_mlx, lst->p_img);
	free(lst->obj);
	free(lst->img_path);
	lst->obj = NULL;
	lst->img_path = NULL;
	free(lst);
}

void	ft_imglstclear(t_img_node **lst, void *p_mlx)
{
	t_img_node	*temp;
	t_img_node	*p_lst;

	if (!lst)
		return ;
	p_lst = *lst;
	while (p_lst)
	{
		temp = p_lst->next;
		ft_imglstdelone(p_lst, p_mlx);
		p_lst = temp;
	}
	*lst = NULL;
}

static void	ft_colorlstdelone(t_color_node *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	else if (del)
		del(lst->obj);
	del(lst);
	lst = NULL;
}

void	ft_colorlstclear(t_color_node **lst, void (*del)(void *))
{
	t_color_node	*temp;
	t_color_node	*p_lst;

	if (!lst)
		return ;
	p_lst = *lst;
	while (p_lst)
	{
		temp = p_lst->next;
		ft_colorlstdelone(p_lst, del);
		p_lst = temp;
	}
}
