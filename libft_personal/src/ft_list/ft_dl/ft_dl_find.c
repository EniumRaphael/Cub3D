/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:05:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 19:00:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_find(const t_dlist *head, const void *data,
		int (*cmp)(const void *, const void *))
{
	t_dlist	*it;

	it = (t_dlist *)head;
	while (it)
	{
		if (data == it->data || (cmp && !cmp(it->data, data)))
			return (it);
		it = it->next;
	}
	return (NULL);
}
