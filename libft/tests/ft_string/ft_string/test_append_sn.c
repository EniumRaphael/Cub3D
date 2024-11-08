/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_append_sn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:55:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 10:30:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_append_sn(void)
{
	t_string	*str;
	t_string	*str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from(" World!!!!");
	ft_string_append_s_n(str, str2, 6);
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11 || str->capacity < 11)
		return (2);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	str = ft_string_from("hi");
	str2 = ft_string_from("ii");
	ft_string_append_s_n(str, str2, 1);
	if (ft_string_cmp(str, "hii") != 0)
		return (3);
	if (str->length != 3 || str->capacity < 3)
		return (4);
	return (ft_string_destroy(&str), ft_string_destroy(&str2), 0);
}
