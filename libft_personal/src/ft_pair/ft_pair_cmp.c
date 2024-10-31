/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:58:24 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 16:52:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"

int	ft_pair_cmp(t_pair *pair1, t_pair *pair2, t_data_cmp cmp)
{
	if (!pair1 && !pair2)
		return (0);
	if (!pair1)
		return (-(pair2 != NULL));
	if (!pair2)
		return (pair1 != NULL);
	if (cmp)
		return (cmp(pair1, pair2));
	return (pair1 - pair2);
}

int	ft_pair_cmp_first(t_pair *pair1, t_pair *pair2, t_data_cmp cmp)
{
	if (!pair1 && !pair2)
		return (0);
	if (!pair1)
		return (-(pair2->first != NULL));
	if (!pair2)
		return (pair1->first != NULL);
	if (cmp)
		return (cmp(pair1->first, pair2->first));
	return (pair1->first - pair2->first);
}

int	ft_pair_cmp_second(t_pair *pair1, t_pair *pair2, t_data_cmp cmp)
{
	if (!pair1 && !pair2)
		return (0);
	if (!pair1)
		return (-(pair2->second != NULL));
	if (!pair2)
		return (pair1->second != NULL);
	if (cmp)
		return (cmp(pair1->second, pair2->second));
	return (pair1->second - pair2->second);
}
