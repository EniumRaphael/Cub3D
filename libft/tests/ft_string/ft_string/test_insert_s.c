/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insert_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/03 10:18:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_insert_s(void)
{
	t_string	*str;
	t_string	*str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from(" World");
	ft_string_insert_s(str, str2, 0);
	if (ft_string_cmp(str, " WorldHello") != 0)
		return (1);
	if (str->length != 11 || str->capacity < 11)
		return (2);
	ft_string_insert_s(str, str2, 99);
	if (ft_string_cmp(str, " WorldHello World") != 0)
		return (3);
	if (str->length != 17 || str->capacity < 17)
		return (4);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	return (0);
}
