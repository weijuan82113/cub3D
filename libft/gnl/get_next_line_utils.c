/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:15:06 by wchen             #+#    #+#             */
/*   Updated: 2023/09/25 22:25:17 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (*c++ != '\0')
		i++;
	return (i);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*p_dest = (unsigned char *)s;
	const unsigned char		p_src = c;

	i = 0;
	while (i < n)
	{
		if (*p_dest == p_src)
			return ((void *)p_dest);
		p_dest++;
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r_chr;
	char	*p_chr;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	r_chr = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!r_chr)
		return (NULL);
	p_chr = r_chr;
	i = 0;
	while (s1[i] != '\0')
		*r_chr++ = s1[i++];
	if (*s1 != '\0')
		free(s1);
	while (*s2 != '\0')
		*r_chr++ = *s2++;
	*r_chr = '\0';
	return (p_chr);
}
