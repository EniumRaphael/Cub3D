/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:28:30 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/19 18:20:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_string.h"

void	*ft_calloc(size_t nmemb, size_t weight)
{
	void	*ret;
	size_t	tot;

	if (nmemb == 0 || weight == 0)
		return (ft_malloc(0));
	if (nmemb > SIZE_MAX / weight)
		return (NULL);
	tot = nmemb * weight;
	ret = ft_malloc(tot);
	if (!ret)
		return (NULL);
	return (ft_memset(ret, 0, tot));
}
