/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:19:33 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:28:41 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_unnbr_fd(unsigned int n, int fd)
{
	char	num;

	if (n > 9)
	{
		ft_put_unnbr_fd(n / 10, fd);
		ft_put_unnbr_fd(n % 10, fd);
	}
	else
	{
		num = n + '0';
		ft_putchar_fd(num, fd);
	}
}

int	print_unint(unsigned int integer)
{
	int				count;
	unsigned int	temp_int;

	count = 0;
	temp_int = integer;
	if (integer == 0)
		count ++;
	while (temp_int != 0)
	{
		count ++;
		temp_int /= 10;
	}
	ft_put_unnbr_fd(integer, 1);
	return (count);
}
