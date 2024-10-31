/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insert_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/03 10:15:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_insert_c(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_insert_c(str, ' ', 0);
	if (ft_string_cmp(str, " Hello") != 0)
		return (1);
	if (str->length != 6 || str->capacity < 6)
		return (2);
	ft_string_insert_c(str, '!', 99);
	if (ft_string_cmp(str, " Hello!") != 0)
		return (3);
	if (str->length != 7 || str->capacity < 7)
		return (4);
	ft_string_destroy(&str);
	return (0);
}
