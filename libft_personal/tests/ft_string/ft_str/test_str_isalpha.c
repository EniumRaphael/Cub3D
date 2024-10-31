/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isalpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 07:43:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_isalpha(void)
{
	if (ft_str_isalpha("HelloWorld") != 1)
		return (1);
	if (ft_str_isalpha("Hello World") != 0)
		return (2);
	if (ft_str_isalpha("HelloWorld!") != 0)
		return (3);
	if (ft_str_isalpha("HelloWorld42") != 0)
		return (4);
	if (ft_str_isalpha("HelloWorld\0") != 1)
		return (5);
	if (ft_str_isalpha("") != 0)
		return (6);
	if (ft_str_isalpha(NULL) != false)
		return (7);
	return (0);
}
