/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:50:00 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/03 10:39:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_string_set(void)
{
	t_string	*str;
	const char	*src;
	const char	*res;

	src = "Hello world this is zod!";
	str = ft_string_new(0);
	ft_string_set(str, src);
	res = ft_string_get(str);
	if (ft_strcmp(src, res) != 0)
		return (1);
	ft_string_destroy(&str);
	str = ft_string_new(99);
	ft_string_set(str, src);
	res = ft_string_get(str);
	if (ft_strcmp(src, res) != 0)
		return (2);
	ft_string_destroy(&str);
	return (0);
}
