/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:16:17 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:29:04 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len_s;

	if (fd < 0)
		return ;
	if (!s)
		return ;
	len_s = ft_strlen(s);
	write (fd, s, len_s);
	return ;
}
// #include <stdio.h>
// #include <fcntl.h>
// #include <sys/types.h>
// #include <sys/stat.h>

// int main(void)
// {
// 	int fd;
// 	char s[] = "bcdefg";

// 	fd = 0;
// 	fd = open("./hoge.txt", O_RDWR);
// 	printf("fd %d \n",fd);
// 	ft_putstr_fd(s, fd);
// 	return 0;
// }
