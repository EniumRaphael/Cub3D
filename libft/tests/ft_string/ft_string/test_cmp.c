/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 19:20:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_cmp(void)
{
	t_string	*str;

	str = ft_string_from("Hello World");
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (ft_string_cmp(str, "Hello Warld!") != 'o' - 'a')
		return (2);
	if (ft_string_cmp(str, "Hello Wprld!") != 'o' - 'p')
		return (3);
	if (ft_string_cmp(str, "Hello World!") != '\0' - '!')
		return (4);
	if (ft_string_cmp(str, "Hell") != 'o' - '\0')
		return (5);
	ft_string_destroy(&str);
	return (0);
}
