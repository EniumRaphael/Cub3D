/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 19:23:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_ncmp(void)
{
	t_string	*str;

	str = ft_string_from("Hello World");
	if (ft_string_ncmp(str, "Hello World", 11) != 0)
		return (1);
	if (ft_string_ncmp(str, "Hello_foobar", 5) != 0)
		return (2);
	if (ft_string_ncmp(str, "Hello World!", 12) == 0)
		return (3);
	ft_string_destroy(&str);
	return (0);
}
