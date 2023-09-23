/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:11:43 by wchen             #+#    #+#             */
/*   Updated: 2022/12/28 16:19:33 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (SSIZE_MAX / count < size)
		return (NULL);
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (ptr);
	ptr = ft_bzero(ptr, size * count);
	return ((void *)ptr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    *st_cp;
//     char    *ft_cp;
//     puts("=== honke std lib ===\n");
//     st_cp =    calloc(2, 2);

//     system("leaks -q a.out");
//  free(st_cp);

// 	puts("\n=== libft ===\n");
//     ft_cp =    ft_calloc(2, 2);

//     system("leaks -q a.out");
//   free(ft_cp);
// }
