/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_img_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:59:46 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 17:31:58 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img_node	*ft_new_imglst(void *mlx, char *obj, char *path)
{
	t_img_node	*img;

	if (!(img = malloc(sizeof(t_img_node))))
		return NULL;
	if (!(img->obj = ft_cut_tr(obj)))
		return NULL;
	if (!(img->img_path = ft_cut_tr(path)))
		return NULL;
	img->h = img_h;
	img->w = img_w;
	if(!(img->p_img = mlx_xpm_file_to_image(mlx, path, &img->h, &img->w)))
		return (NULL);
	img->next = NULL;
	return (img);
}

bool ft_imglstadd_back(t_img_node **head, t_img_node *new)
{
	t_img_node	*tail;

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

bool add_img_lst(t_mlx *mlx, char** split)
{
	if (!mlx->g->img_lst)
	{
		if (!(mlx->g->img_lst = ft_new_imglst(mlx->p_mlx, split[0], split[1])))
			return (ft_error(IMG_INITIAL_ERR));
	}
	else
		return (ft_imglstadd_back(&(mlx->g->img_lst), ft_new_imglst(mlx->p_mlx, split[0], split[1])));
	if (!mlx->g->img_lst)
		return (ft_error(MALLOC_ERR));
	return (false);
}