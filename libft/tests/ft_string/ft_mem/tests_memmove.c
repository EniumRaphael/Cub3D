/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memmove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:39 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/26 19:27:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

// last ft_memmove is a test to check that we do nothing on
// dst if src and dst are the same otherwise it will segfault
int	test_memmove(void)
{
	char		str[10];
	const char	str3[] = "1234567a9";

	ft_strlcpy(str, "123456789", 10);
	ft_memmove(str, "abc", 3);
	if (ft_memcmp(str, "abc456789", 10) != 0)
		return (1);
	ft_memmove(str, str3, 10);
	if (ft_memcmp(str, str3, 10) != 0)
		return (2);
	ft_memmove(str, str + 2, 5);
	if (ft_memcmp(str, "3456767a9", 10) != 0)
		return (3);
	ft_memmove(str + 2, str, 5);
	if (ft_memcmp(str, "3434567a9", 10) != 0)
		return (4);
	ft_memmove(str, str, 999);
	return (0);
}
