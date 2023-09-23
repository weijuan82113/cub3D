/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:39:10 by wchen             #+#    #+#             */
/*   Updated: 2022/12/11 23:29:12 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}
// #include <stdio.h>

// int main (void)
// {
// 	char 	*content_node = "abcd";
// 	char 	*content_new_node = "efgh";
// 	t_node	*new_node;
// 	t_node	*list_node;
// 	t_node	**lst;
// 	t_node	*list_last;
// 	//char	*str;

// 	lst = &list_node;
// 	new_node = ft_lstnew(content_new_node);
// 	list_node = ft_lstnew(content_node);
// 	ft_lstadd_front(lst, new_node);
// 	list_last = ft_lstlast(*lst);
// 	//str = (char *)list_last -> content;
// 	printf("content of last is %s \n", (char *)list_last -> content);
// 	return (0);
// }
