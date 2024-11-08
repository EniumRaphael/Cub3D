/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:19:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 09:00:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strtrim(void)
{
	const char	*str_ugly = "  Hello World!  ";
	const char	*str_ugly_front = "  Hello World!";
	char		*res[7];

	res[0] = ft_strtrim(ft_strchr(str_ugly, 'H'), " ");
	res[1] = ft_strtrim(str_ugly, " ");
	res[2] = ft_strtrim(str_ugly_front, " ");
	res[3] = ft_strtrim(str_ugly, " !Wd");
	res[4] = ft_strtrim(str_ugly, NULL);
	res[5] = ft_strtrim("   ", " ");
	res[6] = ft_strtrim(NULL, " ");
	if (ft_strcmp(res[0], "Hello World!") != 0 || ft_strcmp(res[1], \
	"Hello World!") != 0 || ft_strcmp(res[2], "Hello World!") != 0 || \
	ft_strcmp(res[3], "Hello Worl") != 0 || ft_strcmp(res[4], str_ugly) \
	!= 0 || ft_strcmp(res[5], "") != 0 || res[6])
		return (1);
	ft_apply_2d((void **)res, free);
	return (0);
}
