/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imageline_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:06:50 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/05 12:44:30 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_draw_util.h"

static t_color_node	*search_node(t_color_node *first, const char *src)
{
	while (first != NULL)
	{
		if (ft_strncmp(first->obj, src, ft_strlen(src)) == 0)
			return (first);
		first = first->next;
	}
	return (NULL);
}

void	set_background(t_mlx *mlx, int x)
{
	int				j;
	unsigned int	*path;
	int				ceil;
	int				floor;

	path = (unsigned int *)mlx->path + x * mlx->bpp / 8;
	ceil = search_node(mlx->g->color_lst, "C")->rgb_int;
	floor = search_node(mlx->g->color_lst, "F")->rgb_int;
	j = 0;
	while (j < WIN_Y)
	{
		if (j < WIN_Y / 2)
			*(path + j * mlx->length) = ceil;
		else
			*(path + j * mlx->length) = floor;
		j++;
	}
}

void	set_image(t_mlx *mlx, t_imgline img, int x, double tall)
{
	int				y;
	unsigned int	*path;
	unsigned int	*i_path;

	if (EYE_LINE * tall > WIN_Y / 2)
		y = -WIN_Y / 2 + 1;
	else
		y = -EYE_LINE * tall + 1;
	path = mlx->path + x * mlx->bpp / 8;
	i_path = img.data->path + img.data->h * img.data->length
		+ img.x * img.data->w / BLOCK * img.data->bpp / 8;
	while (y < (BLOCK - EYE_LINE) * tall && y <= WIN_Y / 2)
	{
		if (img.data != NULL)
			*(path + (WIN_Y / 2 - y) * mlx->length)
				= *(i_path - (int)((y + EYE_LINE - 1) * img.data->h
						/ (BLOCK * tall)) *img.data->length);
		y ++;
	}
}
