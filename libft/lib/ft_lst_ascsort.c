/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ascsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:02:01 by wchen             #+#    #+#             */
/*   Updated: 2022/12/29 17:23:27 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	front_back_split(t_node *source, t_node **front_ref,
		t_node **back_ref)
{
	t_node	*fast;
	t_node	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

static t_node	*sorted_merge(t_node *a, t_node *b)
{
	t_node	*result;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (*(int *)a->content <= *(int *)b->content)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void	ft_lst_ascsort(t_node **headRef)
{
	t_node	*head;
	t_node	*a;
	t_node	*b;

	head = *headRef;
	if ((head == NULL) || (head->next) == NULL)
		return ;
	front_back_split(head, &a, &b);
	ft_lst_ascsort(&a);
	ft_lst_ascsort(&b);
	*headRef = sorted_merge(a, b);
}
