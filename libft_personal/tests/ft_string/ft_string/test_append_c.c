/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_append_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 10:26:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

// second test for ft_string_append_c is to check in case buffer is greater 
// than current lenght that char will be indeed appended
int	test_string_append_c(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_append_c(str, ' ');
	if (ft_string_cmp(str, "Hello ") != 0)
		return (1);
	if (str->length != 6 || str->capacity < 6)
		return (2);
	ft_string_destroy(&str);
	str = ft_string_from("hi");
	ft_string_append_c(str, 'i');
	if (ft_string_cmp(str, "hii") != 0)
		return (3);
	if (str->length != 3 || str->capacity < 3)
		return (4);
	ft_string_destroy(&str);
	return (0);
}
