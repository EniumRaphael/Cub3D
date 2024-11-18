/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/18 16:38:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

// return elem n
void	*ft_vec_at(t_vector *vec, size_t n)
{
	if (n >= vec->count)
		return (NULL);
	return (vec->datas[n]);
}
