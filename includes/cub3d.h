/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:20 by wchen             #+#    #+#             */
/*   Updated: 2023/10/15 00:03:38 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx-linux/mlx.h"
#include "error_msg.h"
#include "libft.h"
#include "stdio.h"
#include "stdbool.h"

/* ************************** */
/*         function           */
/* ************************** */

void test(void);
bool validation(int argc, char **argv);

/*Error*/
bool	ft_error(char *err_msg);

#endif