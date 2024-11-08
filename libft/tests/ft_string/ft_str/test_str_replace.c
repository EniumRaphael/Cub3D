/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 07:52:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_replace(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_str_replace(str, "World", "Zod");
	if (ft_strcmp(res, "Hello Zod!") != 0)
		return (1);
	free(res);
	res = ft_str_replace(str, "World", "");
	if (ft_strcmp(res, "Hello !") != 0)
		return (2);
	free(res);
	str = "Hello World!";
	res = ft_str_replace(str, "toto", "tutu");
	if (ft_strcmp(res, "Hello World!") != 0)
		return (3);
	free(res);
	return (0);
}
