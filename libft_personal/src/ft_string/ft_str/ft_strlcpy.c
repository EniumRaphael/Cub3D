/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:21:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 08:39:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	if (!dst)
		return (size);
	if (!src)
		return (ft_strlen(dst));
	if (!size)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < size - 1 && src[dst_len])
	{
		dst[dst_len] = src[dst_len];
		dst_len++;
	}
	dst[dst_len] = 0;
	return (src_len);
}
