/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:29:05 by wchen             #+#    #+#             */
/*   Updated: 2023/10/25 23:04:14 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int ft_isstrempty(char *line)
{
	int strlen;
	int i;

	strlen = 0;
	strlen = ft_strlen(line);
	i = 0;
	while(i < strlen)
	{
		if (line[i] > 32)
			return (0);
		i ++;
	}
	return (1);

}
