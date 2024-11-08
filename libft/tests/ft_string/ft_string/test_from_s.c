/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_from_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 19:38:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_from_s(void)
{
	t_string	*str;
	t_string	*str_src;

	str_src = ft_string_from("Hello World");
	str = ft_string_from_s(str_src);
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11 || str->capacity < 11)
		return (2);
	ft_string_destroy(&str);
	str = ft_string_from_s(NULL);
	if (str->length != 0 || str->capacity < 1)
		return (3);
	return (ft_string_destroy(&str), ft_string_destroy(&str_src), 0);
}
