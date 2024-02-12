/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:49 by wchen             #+#    #+#             */
/*   Updated: 2024/02/12 23:49:25 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q cub3D");
	//system("leaks -q cub3D_bonus");
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (mlx_initial(&mlx) || validation(mlx, argc, argv))
	{
		//int i = 0;
		//t_node* temp = mlx->malloc_check;
		// while(mlx->malloc_check)
		// {
		// 	printf("the index %d, the address %p->\n", i, mlx->malloc_check->content);
		// 	mlx->malloc_check = mlx->malloc_check->next;
		// 	i ++;
		// }
		//ft_lstclear(&temp,free);
		free_all(mlx);
		exit(EXIT_FAILURE);
	}
	draw(mlx);
	return (EXIT_SUCCESS);
}
