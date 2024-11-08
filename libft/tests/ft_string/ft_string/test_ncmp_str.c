/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncmp_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 18:29:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_ncmp_str(void)
{
	t_string	*str;
	t_string	*str2;
	t_string	*str3;
	t_string	*str4;

	str = ft_string_from("Hello World");
	str2 = ft_string_from("Hello Worle");
	str3 = ft_string_from("Hello Worla");
	str4 = ft_string_from("Hello");
	if (ft_string_ncmpstr(str, str2, 10) != 0 || \
	ft_string_ncmpstr(str, str3, 10) != 0)
		return (1);
	if (ft_string_ncmpstr(str, str2, 11) == 0 || \
	ft_string_ncmpstr(str, str3, 11) == 0 || \
	ft_string_ncmpstr(str3, str, 11) == 0)
		return (2);
	if (ft_string_ncmpstr(str2, str, 99) == 0 || \
	ft_string_ncmpstr(str3, str4, 9) == 0)
		return (6);
	return (ft_string_destroy(&str), ft_string_destroy(&str2),
		ft_string_destroy(&str3), ft_string_destroy(&str4), 0);
}
