/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:10:11 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 09:10:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>
#include <stdlib.h>

static int	base_cases(void)
{
	const char	*str = "Hello World!";
	char		*res;
	size_t		size;
	int			ret;

	size = 15;
	res = ft_calloc(sizeof(char), size);
	ret = ft_strlcpy(res, str, size);
	if (ft_strcmp(res, "Hello World!") != 0 || ret != 12)
		return (1);
	free(res);
	res = malloc(sizeof(char) * size);
	ret = ft_strlcpy(res, "This is zod!", size);
	if (ft_strcmp(res, "This is zod!") != 0 || ret != 12)
		return (2);
	return (free(res), 0);
}

static int	error_cases(void)
{
	char	*res;
	size_t	size;
	int		ret;

	size = 15;
	res = ft_calloc(sizeof(char), size);
	ret = ft_strlcpy(res, "This is too large!", size);
	if (ft_strncmp(res, "This is too large!", size - 1) != 0 || \
	ret != (int)ft_strlen("This is too large!"))
		return (3);
	free(res);
	res = ft_calloc(sizeof(char), 1);
	ret = ft_strlcpy(res, "Hello World!", 0);
	if (ft_strcmp(res, "") != 0 || ret != 12)
		return (4);
	ret = ft_strlcpy(res, NULL, 42);
	if (ft_strcmp(res, "") != 0 || ret != 0)
		return (5);
	ret = ft_strlcpy(NULL, "Hello World!", 42);
	if (ret != 42)
		return (6);
	return (free(res), 0);
}

int	test_strlcpy(void)
{
	int	ret;

	ret = base_cases();
	if (ret != 0)
		return (ret);
	ret = error_cases();
	if (ret != 0)
		return (ret + 10);
	return (0);
}
