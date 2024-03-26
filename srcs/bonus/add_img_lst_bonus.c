/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_img_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:59:46 by wchen             #+#    #+#             */
/*   Updated: 2024/03/19 23:48:58 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img_node	*free_img(int type, t_img_node *img)
{
	if (type == OBJ)
		free(img);
	else if (type == IMG_PATH)
	{
		free(img->obj);
		free(img);
	}
	else if (type == P_IMG)
	{
		free(img->img_path);
		free(img->obj);
		free(img);
	}
	return (NULL);
}

static t_img_node	*ft_new_imglst(void *mlx, char *obj, char *path)
{
	t_img_node	*img;

	img = malloc(sizeof(t_img_node));
	if (!img)
		return (NULL);
	img->obj = ft_strdup(obj);
	if (!img->obj)
		return (free_img(OBJ, img));
	img->img_path = ft_strdup(path);
	if (!img->img_path)
		return (free_img(IMG_PATH, img));
	img->h = IMG_H;
	img->w = IMG_W;
	img->p_img = mlx_xpm_file_to_image(mlx, img->img_path, &img->h, &img->w);
	if (!img->p_img)
		return (free_img(P_IMG, img));
	img->path = mlx_get_data_addr(img->p_img, &img->bpp, &img->length,
			&img->endian);
	img->next = NULL;
	return (img);
}

static void	ft_imglstadd_back(t_img_node **head, t_img_node *new)
{
	t_img_node	*tail;

	if (!*head)
		*head = new;
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new;
	}
}

bool	add_img_lst(t_mlx *mlx, char **split)
{
	t_img_node	*new_image;

	errno = 0;
	new_image = ft_new_imglst(mlx->p_mlx, split[0], split[1]);
	if (!new_image)
		return (ft_error(IMG_INITIAL_ERR));
	ft_imglstadd_back(&(mlx->g->img_lst), new_image);
	return (false);
}
