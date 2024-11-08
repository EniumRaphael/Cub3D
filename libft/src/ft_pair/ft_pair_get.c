/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:57:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 16:30:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair_types.h"
#include <stddef.h>

void	*ft_pair_first(t_pair *pair)
{
	if (!pair)
		return (NULL);
	return (pair->first);
}

void	*ft_pair_second(t_pair *pair)
{
	if (!pair)
		return (NULL);
	return (pair->second);
}
