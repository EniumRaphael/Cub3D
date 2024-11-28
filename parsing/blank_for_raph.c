/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blank_for_raph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 06:44:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/28 13:59:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"

#include "ft_string.h"
#include <stdlib.h>

static t_tile char_to_tile(char c)
{
	if (c == '1' || c == ' ')
		return ((t_tile)WALL);
	return ((t_tile)EMPTY);
}

/// @brief Createsa a blank map for rapahael to test the raycasting
/// @param info The structure containing the information about the game
/// @return void
/// @note based on map:
/// 11111
/// 10001
/// 10S01
/// 10001
/// 10111
/// 111  
/// @note The blank does not fill in the textures.
void blank(t_info *info)
{
	int i = 0;

	info->map.size.x = 5;
	info->map.size.y = 6;
	info->map.player_pos.x = 2.5;
	info->map.player_pos.y = 2.5;
	info->map.fraw = malloc(sizeof(char *) * 6);
	info->map.fraw[0] = ft_strdup("11111");
	info->map.fraw[1] = ft_strdup("10001");
	info->map.fraw[2] = ft_strdup("10S01");
	info->map.fraw[3] = ft_strdup("10001");
	info->map.fraw[4] = ft_strdup("10111");
	info->map.fraw[5] = ft_strdup("11111");
	info->map.map = ft_calloc(sizeof(t_tile), (info->map.size.y * info->map.size.x));

	while (i < info->map.size.y * info->map.size.x)
	{
		info->map.map[i] = char_to_tile (
		info->map.fraw[i / info->map.size.x][i % info->map.size.x]);
		i++;
	}
}
