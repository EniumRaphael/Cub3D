/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/03 10:14:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_insert(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_insert(str, " World", 0);
	if (ft_string_cmp(str, " WorldHello") != 0)
		return (1);
	if (str->length != 11 || str->capacity < 11)
		return (2);
	ft_string_insert(str, "!", 99);
	if (ft_string_cmp(str, " WorldHello!") != 0)
		return (3);
	if (str->length != 12 || str->capacity < 12)
		return (4);
	ft_string_destroy(&str);
	return (0);
}
