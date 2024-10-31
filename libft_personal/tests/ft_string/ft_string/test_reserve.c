/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reserve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/03 10:36:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_reserve(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_reserve(str, 42);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5 || str->capacity < 42)
		return (2);
	ft_string_reserve(str, 10);
	if (ft_string_cmp(str, "Hello") != 0)
		return (3);
	if (str->length != 5 || str->capacity < 42)
		return (4);
	ft_string_destroy(&str);
	return (0);
}
