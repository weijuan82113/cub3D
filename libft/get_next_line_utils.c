/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:13:08 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 19:44:24 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*get_next_line_utils(char const *s1, char const *s2)
{
	char	*r_chr;
	char	*p_chr;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	r_chr = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!r_chr)
		return (NULL);
	p_chr = r_chr;
	i = 0;
	while (s1[i] != '\0')
		*r_chr++ = s1[i++];
	if (*s1 != '\0')
		free((void *)s1);
	while (*s2 != '\0')
		*r_chr ++ = *s2 ++;
	*r_chr = '\0';
	return (p_chr);
}
