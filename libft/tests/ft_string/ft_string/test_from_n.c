/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_from_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 19:36:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_from_n(void)
{
	t_string	*str;

	str = ft_string_from_n("Hello World", 5);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5 || str->capacity < 5)
		return (2);
	ft_string_destroy(&str);
	str = ft_string_from_n(NULL, 5);
	if (str->length != 0 || str->capacity < 1)
		return (3);
	ft_string_destroy(&str);
	str = ft_string_from_n("Hello World", 0);
	if (str->length != 0 || str->capacity < 1)
		return (4);
	return (ft_string_destroy(&str), 0);
}
