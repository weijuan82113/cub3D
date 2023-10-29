/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:35:26 by wchen             #+#    #+#             */
/*   Updated: 2023/10/29 17:04:42 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void ft_imglstclear(t_img_node **lst, void (*del)(void*))
{
	t_img_node *temp;
	t_img_node *p_lst;

	if (!lst)
		return ;
	p_lst = *lst;
	while (p_lst)
	{

	}

}



void free_g_board(t_g_board *g)
{
	ft_lstclear(g, free);
	ft_imglstclear(g->img_lst, free)

}

void free_all(t_mlx *mlx)
{
	if(mlx->g)
		free_g_board(mlx->g);
}

int		destroy_hook(t_mlx *mlx)
{
	free_all(mlx);
	return (0);
}