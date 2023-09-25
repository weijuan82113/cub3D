/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:41:23 by wchen             #+#    #+#             */
/*   Updated: 2022/12/16 01:13:19 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_enqueue(t_queue *q, void *content)
{
	t_node	*temp;

	temp = ft_lstnew(content);
	if (q->rear == NULL)
	{
		q->front = temp;
		q->rear = temp;
		return ;
	}
	q->rear->next = temp;
	q->rear = temp;
}
