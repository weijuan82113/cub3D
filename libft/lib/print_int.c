/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:19:33 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:28:40 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(int integer)
{
	int	count;
	int	temp_int;

	count = 0;
	temp_int = integer;
	if (integer == 0)
		count++;
	if (temp_int < 0)
		count++;
	while (temp_int != 0)
	{
		count++;
		temp_int /= 10;
	}
	ft_putnbr_fd(integer, 1);
	return (count);
}
