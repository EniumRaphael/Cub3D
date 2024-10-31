/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 19:34:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_new(void)
{
	t_string	*str;

	str = ft_string_new(42);
	if (!str->str || str->length != 0 || str->capacity < 42)
		return (1);
	ft_string_destroy(&str);
	str = ft_string_new(0);
	if (!str->str || str->length != 0 || str->capacity < 1)
		return (1);
	ft_string_destroy(&str);
	return (0);
}
