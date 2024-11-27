/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:31:06 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/27 11:53:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// proj
#include "cub3d.h"
#include "cub3d_struct.h"
// mlx
#include "mlx_functions.h"
// libft - types
#include "ft_vector_types.h"
#include "ft_optional_types.h"
// libft
#include "ft_math.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "ft_optional.h"

// sys std
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>

void	*load_file(void *data)
{
	t_info	*info;
	char	*file;

	file = NULL;
	info = (t_info *)data;
	file = ft_fd_to_buff(info->map.fd);
	if (file == NULL)
		return (info->errno_state = errno,
		info->last_error = ERROR_READ_FILE, NULL);
	info->map.fraw = ft_split(file, '\n');
	if (info->map.fraw == NULL)
		return (info->errno_state = errno,
info->last_error = ERROR_MALLOC, NULL);
	ft_free((void **)&file);
	info->last_error = NO_ERROR;
	return (info);
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

bool	load_texture(t_info *info, const char *str, const char **id_str)
{
	size_t		i;
	t_texture	texture;

	i = 0;
	while (i < 4)
	{
		if (ft_strstart_with(str, id_str[i]))
		{
			texture.path = ft_strtrim(str + ft_strlen(id_str[i]), " ");
			if (texture.path == NULL)
				return (info->errno_state = errno,
info->last_error = ERROR_MALLOC, false);
			if (ft_strend_with(texture.path, ".xpm") == false)
				return (info->last_error = ERROR_TEXTURE_FORMAT, false);
			texture.img = mlx_xpm_file_to_image(info->mlx_ptr, texture.path, \
			&texture.width, &texture.height);
			if (texture.img == NULL)
				return (info->errno_state = errno,
info->last_error = ERROR_MLX, false); 
			return (info->map.texture[i] = texture, true);
		}
		i++;
	}
	return (false);
}

bool color_from_str(const char *str, t_color *color)
{
	int		col[4];
	char	**split;

	split = ft_split(str, ',');
	if (split == NULL)
		return (false);
	col[0] = ft_atoi(split[0]);
	col[1] = ft_atoi(split[1]);
	col[2] = ft_atoi(split[2]);
	if (split[3])
		col[3] = ft_atoi(split[3]);
	else
		col[3] = 255;
	if (col[0] < 0 || col[0] > 255 || col[1] < 0 || col[1] > 255 || \
	col[2] < 0 || col[2] > 255 || col[3] < 0 || col[3] > 255)
		return (false);
	*color = (t_color){.r = col[0], .g = col[1], .b = col[2], .a = col[3]};
	ft_free_2d((void **)split);
	return (true);
}

bool	load_bg(t_info *info, const char *line, const char **id_str)
{
	t_color	color;
	size_t		i;

	i = 0;
	ft_bzero(&color, sizeof(t_color));
	while (id_str[i])
	{
		if (ft_strstart_with(line, id_str[i]) && \
		(color_from_str(line + ft_strlen(id_str[i]), &color) == false ||
		color.a < 255))
			return (info->last_error = ERROR_PARSE, false);
		if (ft_strstart_with(id_str[i], "F "))
			info->map.bg_colors[BG_FLR] = color;
		else
			info->map.bg_colors[BG_CLG] = color;
		i++;
	}
	if (color.color == 0)
		return (info->last_error = ERROR_PARSE, false);
	return (true);
}

void	*load_textures(void *data)
{
	const char	*id_str[] = {"NO ", "SO ", "WE ", "EA ", NULL};
	t_info		*info;
	size_t		i;

	i = 0;
	info = (t_info *)data;
	while (info->map.fraw[i])
	{
		if (is_identifier(info->map.fraw[i], id_str) && \
		load_texture(info, info->map.fraw[i], id_str) == false)
			return (NULL);
		i++;
	}
	return (info);
}

void	*load_bgs(void *data)
{
	const char *id_str[] = {"F ", "C ", NULL};
	t_info	*info;
	size_t	i;

	i = 0;
	info = (t_info *)data;
	while (info->map.fraw[i])
	{
		if (is_identifier(info->map.fraw[i], id_str) && \
		load_bg(info, info->map.fraw[i], id_str) == false)
			return (NULL);
		i++;
	}
	return (info);
}

void *ft_strchrs(const char *str, const char *chrs)
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
		if (str[i] == '1' || i[str] == ' ')
			tile[i].raw_tile = WALL;
		else
			tile[i].raw_tile = EMPTY;
		i++;
	}
	while (i < size)
		tile[i++].raw_tile = WALL;
}

t_vector	*load_vector(t_map *map)
{
	const char *id_str__all[] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
	t_vector	*str_map;
	size_t		i;

	str_map = ft_vec_new();
	if (str_map == NULL)
		return (NULL);
	i = 0;
	while (map->fraw[i] &&
	is_identifier(map->fraw[i], id_str__all))
		i++;
	while (map->fraw[i + map->size.y])
	{
		map->size.x = ft_max(map->size.x, ft_strlen(map->fraw[i]));
		ft_vec_add(&str_map, map->fraw[i + map->size.y++]);
	}
	return (str_map);
}

void	*load_tiles(void *data)
{
	t_info		*info;
	t_vector	*str_map;
	size_t		i;
	t_dpoint	pos;

	info = (t_info *)data;
	str_map = load_vector(&info->map);
	if (!str_map)
		return (info->last_error = ERROR_MALLOC, NULL);
	info->map.map = ft_calloc(sizeof(t_tile), \
	(info->map.size.y * info->map.size.x));
	if (!info->map.map)
		return (ft_vec_destroy(&str_map), \
		info->last_error = ERROR_MALLOC, NULL);
	i = 0;
	ft_bzero(&pos, sizeof(t_dpoint));
	while (ft_vec_at(str_map, i))
	{
		str_to_tile(ft_vec_at(str_map, i), info->map.map + \
		(i * info->map.size.x), info->map.size.x);
		if (ft_strchrs(ft_vec_at(str_map, i), "SNWE"))
		{
			if (pos.x != 0 || pos.y != 0 || i == 0)
				return (ft_vec_destroy(&str_map), \
				info->last_error = ERROR_PARSE, NULL);
			pos.x = i + .5;
			pos.y = ft_strchrs(ft_vec_at(str_map, i), "SNWE") - ft_vec_at(str_map, i) + .5;
			info->player.pos = pos;
		}
		i++;
	}
	return (ft_vec_destroy(&str_map), info);
}

t_tile	*c3_get_cell(t_tile *map, t_ipoint dimensions, t_ipoint pos)
{
	return (map + (pos.y * dimensions.x + pos.x));
}

bool	flood_fill(t_tile *tiles, t_ipoint pos, t_ipoint maxs)
{
	t_tile			*current;
	size_t			i;
	const t_ipoint	to_check[] = {
		(t_ipoint){pos.x + 1, pos.y},
		(t_ipoint){pos.x - 1, pos.y},
		(t_ipoint){pos.x, pos.y + 1},
		(t_ipoint){pos.x, pos.y - 1},
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

void	parse_map(t_info *info)
{
	t_optional			opt;
	const t_data_tr_i	function_list[] = {
		load_file,
		load_textures,
		load_bgs,
		load_tiles,
		traverse_map,
		NULL,
	};

	opt = (t_optional){.val = info, .pres = OPT_SOME};
	info->map.path = info->cli_ctx.file;
	if (ft_optional_chain(&opt, function_list) == false)
		return (c3_perror(info), (void)0);
}
