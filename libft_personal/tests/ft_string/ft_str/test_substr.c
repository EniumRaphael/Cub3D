/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:25:34 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 09:02:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_substr(void)
{
	const char	*str = "Hello World!";
	char		*res[7];

	res[0] = ft_substr(str, 0, 5);
	res[1] = ft_substr(str, 6, 6);
	res[2] = ft_substr(str, 6, 100);
	res[3] = ft_substr(str, 6, 0);
	res[4] = ft_substr(str, 12, 0);
	res[5] = ft_substr(str, 12, 100);
	res[6] = ft_substr(NULL, 0, 5);
	if (ft_strcmp(res[0], "Hello") != 0 || ft_strcmp(res[1], "World!") != 0
		|| ft_strcmp(res[2], "World!") != 0)
		return (1);
	if (ft_strcmp(res[3], "") != 0 || ft_strcmp(res[4], "") != 0
		|| ft_strcmp(res[5], "") != 0 || res[6])
		return (2);
	ft_apply_2d((void **)res, free);
	return (0);
}
