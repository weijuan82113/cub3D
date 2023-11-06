/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:08:32 by wchen             #+#    #+#             */
/*   Updated: 2023/11/06 22:13:36 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_imglstdelone(t_img_node *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	else if (del)
	{
		del(lst->obj);
		del(lst->img_path);
		del(lst->p_img);
	}
	del(lst);
	lst = NULL;
}

void	ft_imglstclear(t_img_node **lst, void (*del)(void *))
{
	t_img_node	*temp;
	t_img_node	*p_lst;

	if (!lst)
		return ;
	p_lst = *lst;
	while (p_lst)
	{
		temp = p_lst->next;
		ft_imglstdelone(p_lst, del);
		p_lst = temp;
	}
}

void	ft_colorlstdelone(t_color_node *lst, void (*del)(void *))
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
