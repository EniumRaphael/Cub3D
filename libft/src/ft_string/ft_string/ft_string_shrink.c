/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_shrink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:31:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/03 10:56:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_shrink(t_string *str)
{
	char	*new;

	if (str->capacity <= str->length + 1)
		return (0);
	new = ft_realloc(str->str, str->length + 1, str->capacity);
	if (!new)
		return (-1);
	str->str = new;
	str->capacity = str->length + 1;
	return (0);
}
