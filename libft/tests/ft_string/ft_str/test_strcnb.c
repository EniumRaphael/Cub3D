/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcnb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:47:58 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 08:06:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>

int	test_strcnb(void)
{
	if (ft_strcnb("Hello World", 'o') != 2)
		return (1);
	if (ft_strcnb("Hello World", 'z') != 0)
		return (2);
	if (ft_strcnb("Hello World", 'H') != 1)
		return (3);
	if (ft_strcnb("Hello World", 'd') != 1)
		return (4);
	if (ft_strcnb("Hello World", 'l') != 3)
		return (5);
	if (ft_strcnb(NULL, ' ') != 0)
		return (6);
	if (ft_strcnb("toto", '\0') != 1)
		return (7);
	return (0);
}
