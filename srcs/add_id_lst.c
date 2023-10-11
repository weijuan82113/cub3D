/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_id_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:59:46 by wchen             #+#    #+#             */
/*   Updated: 2023/10/11 21:07:20 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*ft_new_idlst(char *obj, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return NULL;
	img->obj = obj;
	img->img_path = path;
	img->next = NULL;
	return (img);
}

bool ft_idlstadd_back(t_img **head, t_img *new)
{
	t_img	*tail;

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

bool add_id_lst(t_g_board *g_board, char** split)
{
	if (!g_board->img_lst)
		g_board->img_lst = ft_new_idlst(split[0], split[1]);
	else
		return (ft_idlstadd_back(&(g_board->img_lst), ft_new_idlst(split[0], split[1])));
	if (!g_board->img_lst)
		return (ft_error(MALLOC_ERR));
	return (false);
}