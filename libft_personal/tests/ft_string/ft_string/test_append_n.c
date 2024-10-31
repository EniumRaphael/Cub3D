/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_append_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 10:27:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_append_n(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_append_n(str, " World", 5);
	if (ft_string_cmp(str, "Hello Worl") != 0)
		return (1);
	if (str->length != 10)
		return (2);
	if (str->capacity < 10)
		return (3);
	ft_string_destroy(&str);
	str = ft_string_from("hi");
	ft_string_append_n(str, "i", 1);
	if (ft_string_cmp(str, "hii") != 0)
		return (4);
	if (str->length != 3 || str->capacity < 3)
		return (5);
	ft_string_destroy(&str);
	return (0);
}
