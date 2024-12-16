/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:43:17 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/16 09:39:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"

#include "ft_string.h"

#include <X11/X.h>
#include <stdio.h>

t_tile	*c3_get_cell(t_tile *map, t_ipoint dimensions, t_ipoint pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= dimensions.x
		|| pos.y >= dimensions.y)
		return (NULL);
	return (map + (pos.y * dimensions.x + pos.x));
}

bool	is_identifier(const char *str, const char **id_str)
{
	size_t	i;

	i = 0;
	while (id_str[i])
	{
		if (ft_strstart_with(str, id_str[i]))
			return (true);
		i++;
	}
	return (false);
}
