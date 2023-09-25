/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:39:10 by wchen             #+#    #+#             */
/*   Updated: 2022/12/30 19:43:33 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_node *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	else if (del)
		del(lst->content);
	del(lst);
	lst = NULL;
}

// #include <stdio.h>

// int main (void)
// {
// 	char 	*content_node = "abcd";
// 	t_node	*list_node;

// 	list_node = ft_lstnew(content_node);
// 	printf("content of lst before_del
//is %s \n", (char *)(list_node) -> content);
// 	ft_lstdelone(list_node, free);
// 	//printf("content of lst after_del
//is %s \n", (char *)list_node -> content);
// 	return (0);
// }
