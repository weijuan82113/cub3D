/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_img_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:59:46 by wchen             #+#    #+#             */
/*   Updated: 2023/11/03 22:46:54 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img_node	*ft_new_imglst(void *mlx, char *obj, char *path)
{
	t_img_node	*img;

	img = malloc(sizeof(t_img_node));
	if (!img)
		return (NULL);
	img->obj = ft_cut_tr(obj);
	if (!img->obj)
		return (NULL);
	img->img_path = ft_cut_tr(path);
	if (!img->img_path)
		return (NULL);
	img->h = IMG_H;
	img->w = IMG_W;
	img->p_img = mlx_xpm_file_to_image(mlx, img->img_path, &img->h,
			&img->w);
	if (!img->p_img)
		return (NULL);
	img->path = mlx_get_data_addr(img->p_img, &img->bpp, &img->length, &img->endian);
	img->next = NULL;
	return (img);
}

bool	ft_imglstadd_back(t_img_node **head, t_img_node *new)
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

bool	add_img_lst(t_mlx *mlx, char **split)
{
	errno = 0;
	if (!mlx->g->img_lst)
		mlx->g->img_lst = ft_new_imglst(mlx->p_mlx, split[0], split[1]);
	else
		return (ft_imglstadd_back(&(mlx->g->img_lst), ft_new_imglst(mlx->p_mlx,
					split[0], split[1])));
	if (!mlx->g->img_lst)
		return (ft_error(IMG_INITIAL_ERR));
	return (false);
}
