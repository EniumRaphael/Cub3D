/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:55:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 09:09:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t			len_small;
	const size_t	len_big = n;

	if (!big || !small || n == 0)
		return (NULL);
	len_small = ft_strlen(small);
	while (n-- > len_small && *big)
		if (ft_strncmp(big++, small, len_small) == 0)
			return ((char *)big - 1);
	if (len_big >= len_small && ft_strncmp(big, small, len_small) == 0)
		return ((char *)big);
	return (NULL);
}
