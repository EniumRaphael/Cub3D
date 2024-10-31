/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:14:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/19 18:15:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

void	**ft_memmap(void **src, size_t nb_e, t_data_tr f)
{
	void	**dst;
	size_t	i;

	if (!src || !f || !nb_e)
		return (NULL);
	dst = ft_malloc((nb_e + 1) * sizeof(void *));
	if (!dst)
		return (NULL);
	dst[nb_e] = NULL;
	i = 0;
	while (i < nb_e)
	{
		dst[i] = f(src[i]);
		i++;
	}
	return (dst);
}
