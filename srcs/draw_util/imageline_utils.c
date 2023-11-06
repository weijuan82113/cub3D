/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imageline_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:06:50 by kitsuki           #+#    #+#             */
/*   Updated: 2023/11/06 22:50:21 by kitsuki          ###   ########.fr       */
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
	int		j;
	void	*path;
	int		ceil;
	int		floor;

	path = mlx->path + x * mlx->bpp / 8;
	ceil = search_node(mlx->g->color_lst, "C")->rgb_int;
	floor = search_node(mlx->g->color_lst, "F")->rgb_int;
	j = 0;
	while (j < WIN_Y)
	{
		if (j < WIN_Y / 2)
			*(unsigned int *)(path + j * mlx->length) = ceil;
		else
			*(unsigned int *)(path + j * mlx->length) = floor;
		j++;
	}
}

void	set_image(t_mlx *mlx, t_imgline img, int x, double tall)
{
	int		y;
	void	*path;
	void	*i_path;

	if (tall <= 0)
		return ;
	if (BLOCK / 2 * tall > WIN_Y / 2)
		y = -WIN_Y / 2 + 1;
	else
		y = -BLOCK / 2 * tall + 1;
	path = mlx->path + x * mlx->bpp / 8;
	i_path = img.data->path + img.data->h * img.data->length
		+ img.x * img.data->w / BLOCK * img.data->bpp / 8;
	while (y < (BLOCK - BLOCK / 2) * tall && y < WIN_Y / 2)
	{
		if (img.data != NULL)
			*(unsigned int *)(path + (WIN_Y / 2 - y) * mlx->length)
				= *(unsigned int *)(i_path - (int)((y + BLOCK / 2 * tall - 1)
						* img.data->h / (BLOCK * tall)) *img.data->length);
		y ++;
	}
}
