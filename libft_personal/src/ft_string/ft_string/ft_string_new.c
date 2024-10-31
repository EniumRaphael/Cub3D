/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:00:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 10:22:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string	*ft_string_new(size_t capacity)
{
	t_string	*new;

	new = ft_calloc(1, sizeof(t_string));
	if (!new)
		return (NULL);
	if (capacity < T_STRING_BUFF)
		capacity = T_STRING_BUFF;
	new->str = ft_calloc(capacity, sizeof(char));
	if (!new->str)
		return (ft_free((void **)&new), NULL);
	new->capacity = capacity;
	new->length = 0;
	return (new);
}
