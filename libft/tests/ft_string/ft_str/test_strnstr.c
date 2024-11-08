/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:24:10 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 08:44:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

int	test_strnstr(void)
{
	char	*str;
	char	*res;

	str = "The cake is a lie !\0I'm hidden lol\n";
	if (ft_strnstr(str, "The cake is a lie !", 100) != str)
		return (1);
	if (ft_strnstr(str, "The cake is a lie !", 20) != str)
		return (2);
	res = ft_strnstr(str, "The cake is a lie !", 19);
	if (!res)
		return (3);
	if (ft_strnstr(str, "The cake is a lie !", 0))
		return (4);
	if (ft_strnstr(str, "hidden", 100))
		return (5);
	if (ft_strnstr(NULL, "hidden", 10) || \
	ft_strnstr(str, NULL, 10))
		return (6);
	return (0);
}
