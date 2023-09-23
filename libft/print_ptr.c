/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:09:11 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:28:46 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(unsigned long long ulonglong_ptr, int fd)
{
	char	num;

	if (ulonglong_ptr > 15)
	{
		ft_putptr_fd(ulonglong_ptr / 16, fd);
		ft_putptr_fd(ulonglong_ptr % 16, fd);
	}
	else
	{
		if (ulonglong_ptr > 9)
			num = (int)ulonglong_ptr - 10 + 'a';
		else
			num = (int)ulonglong_ptr + '0';
		ft_putchar_fd(num, fd);
	}
}

int	print_ptr(unsigned long long ulonglong_ptr)
{
	int					count_digit;
	unsigned long long	temp_intptr;

	if (ulonglong_ptr == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	temp_intptr = ulonglong_ptr;
	count_digit = 2;
	while (temp_intptr != 0)
	{
		count_digit ++;
		temp_intptr /= 16;
	}
	ft_putptr_fd(ulonglong_ptr, 1);
	return (count_digit);
}
