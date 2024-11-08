/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:55:07 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/24 00:10:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair_types.h"
#include "ft_pair.h"

void	ft_pair_set(t_pair *pair, void *first, void *second)
{
	if (!pair)
		return ;
	pair->first = first;
	pair->second = second;
}
