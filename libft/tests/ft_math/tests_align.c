/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_align.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:53:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 17:05:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_align_2(void)
{
	size_t	size;
	size_t	result;

	size = 42;
	result = ft_align_2(size, 4);
	if (result != 44)
		return (1);
	result = ft_align_2(size, 8);
	if (result != 48)
		return (2);
	result = ft_align_2(size, 16);
	if (result != 48)
		return (3);
	size = 275;
	result = ft_align_2(size, 4);
	if (result != 276)
		return (4);
	return (0);
}

int	test_ft_align(void)
{
	size_t	size;
	size_t	result;

	size = 42;
	result = ft_align(size, 4);
	if (result != 44)
		return (1);
	result = ft_align(size, 8);
	if (result != 48)
		return (2);
	result = ft_align(size, 16);
	if (result != 48)
		return (3);
	size = 275;
	result = ft_align(size, 6);
	if (result != 276)
		return (4);
	return (0);
}
