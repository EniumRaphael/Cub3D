/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 10:37:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_rchr(void)
{
	t_string	*str;
	const char	c[] = "z!Hol@\0";
	char		*ptr_exp[sizeof(c) / sizeof(c[0])];
	size_t		i;

	str = ft_string_from("Hello world this is zod!");
	i = 0;
	while (i < sizeof(c) / sizeof(c[0]))
	{
		ptr_exp[i] = ft_strrchr(str->str, c[i]);
		if (ft_string_rchr(str, c[i]) != ptr_exp[i])
			return (i + 1);
		i++;
	}
	ft_string_destroy(&str);
	return (0);
}
