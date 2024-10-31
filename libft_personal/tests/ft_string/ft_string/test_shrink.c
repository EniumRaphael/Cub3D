/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shrink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/03 10:56:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_shrink(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_shrink(str);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5 || str->capacity < 5)
		return (2);
	ft_string_destroy(&str);
	str = ft_string_from("^_^");
	if (str->length != 3 || str->capacity != T_STRING_BUFF)
		return (3);
	ft_string_shrink(str);
	if (ft_string_cmp(str, "^_^") != 0)
		return (4);
	if (str->length != 3 || str->capacity < 3)
		return (5);
	ft_string_shrink(str);
	if (ft_string_cmp(str, "^_^") != 0)
		return (6);
	if (str->length != 3 || str->capacity < 3)
		return (7);
	return (ft_string_destroy(&str), 0);
}
