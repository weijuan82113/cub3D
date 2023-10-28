/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:14:47 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 18:38:12 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_mlx *t_mlx)
{
	(void)t_mlx;
	printf("keycode: %d\n", keycode);
	if (keycode == ESC || keycode == KEY_Q)
	{
		printf("push!\n");
		return(ft_error(GAME_OVER));
	}
	return (0);
}
