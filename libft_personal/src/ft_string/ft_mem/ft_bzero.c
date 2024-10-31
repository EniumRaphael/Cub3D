/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:05:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/26 19:48:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	byte_bzero(char *s, size_t n)
{
	while (n--)
	{
		*s = 0;
		s++;
	}
}

static void	word_bzero(size_t *s, size_t *n)
{
	size_t	word_count;
	size_t	i;

	word_count = *n / sizeof(size_t);
	i = 0;
	while (i < word_count)
	{
		s[i] = 0;
		i++;
	}
	*n %= sizeof(size_t);
}

void	ft_bzero(void *s, size_t n)
{
	if (!n || !s)
		return ;
	if (n < sizeof(size_t))
		return (byte_bzero(s, n));
	byte_bzero(s, (size_t)s % sizeof(size_t));
	n -= (size_t)s % sizeof(size_t);
	s += (size_t)s % sizeof(size_t);
	word_bzero(s, &n);
	byte_bzero(s, n);
}
