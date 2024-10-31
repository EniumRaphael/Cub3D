/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:01:18 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/19 18:18:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include <stdlib.h>

bool	ft_vec_reserve(t_vector **vec, size_t size)
{
	t_vector	ret;
	size_t		i;

	if ((*vec)->cappacity > size)
		return (true);
	ret.datas = ft_malloc(sizeof(void *) * size);
	if (!ret.datas)
		return (false);
	i = 0;
	while (i < (*vec)->count)
	{
		ret.datas[i] = (*vec)->datas[i];
		i++;
	}
	ret.count = (*vec)->count;
	ret.cappacity = size;
	free((*vec)->datas);
	**vec = ret;
	return (true);
}
