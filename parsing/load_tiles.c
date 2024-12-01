/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:47:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 17:53:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "cub3d_parsing.h"

#include "ft_string.h"
#include "ft_vector.h"
#include "ft_math.h"

void	*ft_strchrs(const char *str, const char *chrs)
{
	while (*str)
	{
		if (ft_strchr(chrs, *str))
			return ((void *)str);
		str++;
	}
	return (NULL);
}

void	str_to_tile(const char *str, t_tile *tile, size_t size)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == ' ')
			tile[i].tile_type = WALL;
		else
			tile[i].tile_type = EMPTY;
		i++;
	}
	while (i < size)
		tile[i++].tile_type = WALL;
}

t_vector	*load_vector(t_map *map)
{
	const char	*id_str__all[] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
	t_vector	*str_map;
	size_t		i;

	str_map = ft_vec_new();
	if (str_map == NULL)
		return (NULL);
	i = 0;
	while (map->fraw[i] && is_identifier(map->fraw[i], id_str__all))
		i++;
	while (map->fraw[i + map->size.y])
	{
		map->size.x = ft_max(map->size.x, ft_strlen(map->fraw[i]));
		ft_vec_add(&str_map, map->fraw[i + map->size.y++]);
	}
	return (str_map);
}

int	set_player(t_info *info, int i, t_vector *str_map)
{
	t_dpoint	pos;

	ft_bzero(&pos, sizeof(t_dpoint));
	if (info->player.pos.x != 0 || info->player.pos.y != 0 || i == 0)
		return (ft_vec_destroy(&str_map), info->last_error = ERROR_PARSE, \
		EXIT_FAILURE);
	pos.y = i + .5;
	pos.x = ft_strchrs(ft_vec_at(str_map, i), "SNWE")
		- ft_vec_at(str_map, i) + .5;
	info->player.pos = pos;
	info->player.pos_i = (t_ipoint){.x = (int)pos.x, .y = (int)pos.y};
	return (EXIT_SUCCESS);
}

void	*load_tiles(void *data)
{
	t_info		*info;
	t_vector	*str_map;
	size_t		i;

	info = (t_info *)data;
	str_map = load_vector(&info->map);
	if (!str_map)
		return (info->last_error = ERROR_MALLOC, NULL);
	info->map.map = ft_calloc(sizeof(t_tile), (info->map.size.y
				* info->map.size.x));
	if (!info->map.map)
		return (ft_vec_destroy(&str_map), info->last_error = ERROR_MALLOC,
			NULL);
	i = 0;
	while (ft_vec_at(str_map, i))
	{
		str_to_tile(ft_vec_at(str_map, i), info->map.map + (i
				* info->map.size.x), info->map.size.x);
		if (ft_strchrs(ft_vec_at(str_map, i), "SNWE") && \
		set_player(info, i, str_map) != EXIT_SUCCESS)
			return (NULL);
		i++;
	}
	return (ft_vec_destroy(&str_map), info);
}
