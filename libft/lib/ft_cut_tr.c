/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_tr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:21:40 by wchen             #+#    #+#             */
/*   Updated: 2023/11/01 23:00:26 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cut_tr(char *src_str)
{
	int		str_ntr_len;
	int		i;
	char	*ret_str;

	str_ntr_len = ft_strlen_ntr(src_str);
	ret_str = malloc(sizeof(char) * (str_ntr_len + 1));
	if (!ret_str)
		return (NULL);
	i = 0;
	while (i < str_ntr_len)
	{
		ret_str[i] = src_str[i];
		i ++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
