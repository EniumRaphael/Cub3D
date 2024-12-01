/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:49:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 17:54:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "cub3d_parsing.h"

#include <stdbool.h>

bool	flood_fill(t_tile *tiles, t_ipoint pos, t_ipoint maxs)
{
	size_t			i;
	t_tile			*current;
	const t_ipoint	to_check[] = {
		(t_ipoint){pos.x + 1, pos.y}, (t_ipoint){pos.x - 1, pos.y},
		(t_ipoint){pos.x, pos.y + 1}, (t_ipoint){pos.x, pos.y - 1},
		(t_ipoint){pos.x + 1, pos.y + 1},
		(t_ipoint){pos.x - 1, pos.y + 1},
		(t_ipoint){pos.x + 1, pos.y - 1},
		(t_ipoint){pos.x - 1, pos.y - 1},
	};

	if (pos.x < 0 || pos.y < 0 || pos.x >= maxs.x || pos.y >= maxs.y)
		return (false);
	current = c3_get_cell(tiles, maxs, pos);
	if (current->tile_visited == true || current->tile_type == WALL)
		return (true);
	current->tile_visited = true;
	i = 0;
	while (i != (sizeof(to_check) / sizeof(to_check[0])))
		if (flood_fill(tiles, to_check[i++], maxs) == false)
			return (false);
	return (true);
}

void	*traverse_map(void *data)
{
	t_info		*info;
	t_ipoint	pos_start;

	info = (t_info *)data;
	pos_start = (t_ipoint){.x = info->player.pos.x, .y = info->player.pos.y};
	if (flood_fill(info->map.map, pos_start, info->map.size) == false)
		return (info->last_error = ERROR_PARSE, NULL);
	return (info);
}
