/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:11:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 08:24:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>
#include <stdlib.h>

int	test_strlcat(void)
{
	char	*res;
	size_t	size;
	int		ret;

	size = 15;
	res = malloc(sizeof(char) * size);
	ft_bzero(res, size);
	ret = ft_strlcat(res, "Hello", size);
	if (ft_strcmp(res, "Hello") != 0 || ret != 5)
		return (1);
	ret = ft_strlcat(res, " World!", size);
	if (ft_strcmp(res, "Hello World!") != 0 || ret != 12)
		return (2);
	ret = ft_strlcat(res, "This is zod!", size);
	if (ft_strcmp(res, "Hello World!Th") != 0 || ret != 24)
		return (3);
	ret = ft_strlcat(res, "This is zod!", 5);
	if (ft_strcmp(res, "Hello World!Th") != 0 || ret != 5 + 12)
		return (4);
	if (ft_strlcat(NULL, "test", 0) != 0 || ft_strlcat(NULL, "test", 5) != 0)
		return (5);
	ret = ft_strlcat(res, NULL, size);
	if (ft_strcmp(res, "Hello World!Th") != 0 || ret != 14)
		return (6);
	return (free(res), 0);
}
