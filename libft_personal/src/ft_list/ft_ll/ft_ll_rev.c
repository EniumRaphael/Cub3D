/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_rev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iron <iron@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:22:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 19:01:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_ll_rev(t_list **head)
{
	t_list	*next;
	t_list	*it;
	t_list	*prev;

	if (!head || !*head)
		return (NULL);
	it = *head;
	prev = NULL;
	next = it->next;
	while (next)
	{
		next = it->next;
		it->next = prev;
		prev = it;
		it = next;
	}
	*head = prev;
	return (*head);
}
