/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:47:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/20 17:09:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parsing.h"

#include "ft_string.h"
#include "ft_addons.h"
#include "ft_vector.h"
#include "ft_math.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int	str_to_tile(const char *str, t_tile *tile, size_t size)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			tile[i].tile_type = WALL;
		else if (str[i] == ' ')
			tile[i].tile_type = WALL_ERR;
		else if (!ft_strchr("0NSWE", str[i]))
			return (-1);
		else
			tile[i].tile_type = EMPTY;
		i++;
	}
	while (i < size)
		tile[i++].tile_type = NONE;
	return (0);
}

t_vector	*load_vector(t_map *map)
{
	const char	*id_str__all[] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
	t_vector	*str_map;
	size_t		i;
	size_t		max;

	str_map = ft_vec_new();
	max = 0;
	if (str_map == NULL)
		return (NULL);
	i = 0;
	while (map->fraw[i] && is_identifier(map->fraw[i], id_str__all))
		i++;
	while (map->fraw[i + map->size.y])
	{
		max = ft_max(max, ft_strlen(map->fraw[i + map->size.y]));
		ft_vec_add(&str_map, map->fraw[i + map->size.y++]);
	}
	map->size.x = max;
	return (str_map);
}

#define EPMIM ERROR_PARSE_META_IN_MAP
#define ENP ERROR_NO_PLAYER

t_info	*load_tiles_norm(t_info *info, t_vector *str_map)
{
	size_t	i;

	i = 0;
	info->map.map = ft_calloc(sizeof(t_tile), (info->map.size.y
				* info->map.size.x));
	if (!info->map.map)
		return (ft_vec_destroy(&str_map), sv_errno(info, ERROR_MALLOC), NULL);
	i = 0;
	while (ft_vec_at(str_map, i))
	{
		if (str_to_tile(ft_vec_at(str_map, i), info->map.map + (i \
		* info->map.size.x), info->map.size.x) == -1)
			return (ft_vec_destroy(&str_map), sv_errno(info, EPMIM), NULL);
		if (ft_strchrs(ft_vec_at(str_map, i), "SNWE") && \
		set_player(info, i, str_map) != EXIT_SUCCESS)
			return (NULL);
		i++;
	}
	if (info->player.pos_i.x == 0)
		return (ft_vec_destroy(&str_map), sv_errno(info, ENP), NULL);
	return (ft_vec_destroy(&str_map), info);
}

void	*load_tiles(void *data)
{
	t_info		*info;
	t_vector	*str_map;

	info = (t_info *)data;
	str_map = load_vector(&info->map);
	if (!str_map)
		return (sv_errno(info, ERROR_MALLOC), NULL);
	return (load_tiles_norm(info, str_map));
}
