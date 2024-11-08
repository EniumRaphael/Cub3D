/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:51:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/26 20:46:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_align_2(size_t size, size_t alignment)
{
	return ((size + alignment - 1) & ~(alignment - 1));
}

size_t	ft_align(size_t size, size_t alignment)
{
	if (alignment < 2)
		return (size);
	if (size % alignment == 0)
		return (size);
	size += alignment - size % alignment;
	return (size);
}
