/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 06:04:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/16 09:01:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// dest ft_math/ft_inrange.c
#include <stdbool.h>

bool	ft_inrange_ex(int value, int min, int max)
{
	return (value > min && value < max);
}

bool	ft_inrange(int value, int min, int max)
{
	return (value >= min && value <= max);
}
