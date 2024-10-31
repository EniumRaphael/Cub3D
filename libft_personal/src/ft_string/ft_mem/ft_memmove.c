/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:14:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/11 11:59:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

static	void	*byte_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest > src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

static void	word_memcpy(void *dest, const void *src, size_t *n)
{
	size_t	*casted_dest;
	size_t	*casted_src;
	size_t	word_count;
	size_t	i;

	if (*n < sizeof(size_t))
		return ;
	casted_dest = (size_t *)dest;
	casted_src = (size_t *)src;
	word_count = *n / sizeof(size_t);
	i = 0;
	if (dest < src)
	{
		while (i++ < word_count)
			casted_dest[i - 1] = casted_src[i - 1];
	}
	else
	{
		i = word_count;
		while (i--)
			casted_dest[i] = casted_src[i];
	}
	*n %= sizeof(size_t);
}

/*
	* If src is not aligned then we copy byte by byte otherwise
	* the compiler will need to align each time we pull from src
*/

static void	*ft_memmove_forward(void *dest, const void *src, size_t n)
{
	const void	*ret = dest;
	size_t		align_offset;
	size_t		prev_n;

	if ((size_t)src % sizeof(size_t))
		return (byte_memcpy(dest, src, n));
	align_offset = (size_t)dest % sizeof(size_t);
	byte_memcpy(dest, src, align_offset);
	n -= align_offset;
	src += align_offset;
	dest += align_offset;
	prev_n = n;
	word_memcpy(dest, src, &n);
	dest += prev_n - n;
	src += prev_n - n;
	if (n)
		byte_memcpy(dest, src, n);
	return ((void *)ret);
}

static void	*ft_memmove_backward(void *dest, const void *src, size_t n)
{
	const void	*ret = dest;
	size_t		align_offset;

	if ((size_t)src % sizeof(size_t))
		return (byte_memcpy(dest, src, n));
	align_offset = (size_t)(dest + n) % sizeof(size_t);
	n -= align_offset;
	byte_memcpy(dest + n, src + n, align_offset);
	word_memcpy(dest, src, &n);
	if (n)
		byte_memcpy(dest, src, n);
	return ((void *)ret);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const void	*ret = dest;

	if (dest == src || !n || !dest || !src)
		return ((void *)ret);
	if (n < sizeof(size_t))
		return (byte_memcpy(dest, src, n));
	if (dest < src)
		return (ft_memmove_forward(dest, src, n));
	return (ft_memmove_backward(dest, src, n));
}
