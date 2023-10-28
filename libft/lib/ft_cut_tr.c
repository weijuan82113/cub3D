/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_tr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:21:40 by wchen             #+#    #+#             */
/*   Updated: 2023/10/28 19:18:37 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char *ft_cut_tr(char *src_str)
{
	int str_ntr_len;
	int i;
	char *ret_str;

	str_ntr_len = ft_strlen_ntr(src_str);
	if (!(ret_str = malloc(sizeof(char) * (str_ntr_len + 1))))
		return (NULL);
	i = 0;
	while(i < str_ntr_len)
	{
		ret_str[i] = src_str[i];
		i ++;
	}
	ret_str[i] = '\0';
	return(ret_str);
}