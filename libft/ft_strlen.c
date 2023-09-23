/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:04:40 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:28:58 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (*c++ != '\0')
		i++;
	return (i);
}
// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char * testtext = "";
// 	printf("the string is %s strlen is %ld \n",testtext,ft_strlen(testtext));
// 	printf("the string is %s ft_strlen is %ld \n",testtext,strlen(testtext));
// 	return 0;
// }
