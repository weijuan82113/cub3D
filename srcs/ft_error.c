/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:03:56 by wchen             #+#    #+#             */
/*   Updated: 2023/11/03 23:47:24 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_error(char *err_msg)
{
	char tr;

	tr = '\n';
	if (errno != 0)
		perror(err_msg);
	else
	{
		ft_putstr_fd(err_msg, STDERR_FILENO);
		write(STDERR_FILENO, &tr, 1);
	}
	return (true);
}
