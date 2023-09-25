/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:34:35 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 19:22:35 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r_chr;
	char	*p_chr;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	r_chr = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!r_chr)
		return (NULL);
	p_chr = r_chr;
	while (*s1 != '\0')
		*r_chr ++ = *s1 ++;
	while (*s2 != '\0')
		*r_chr ++ = *s2 ++;
	*r_chr = '\0';
	return (p_chr);
}
// #include <stdio.h>

// int main (void)
// {
// 	char *ch1 = NULL;
// 	char ch2[] = "efrweafawe";
// 	char *ans;
// 	ans = ft_strjoin(ch1, ch2);
// 	printf("the answer is %s\n", ans);
// 	free(ans);

// 	return 0;
// }
