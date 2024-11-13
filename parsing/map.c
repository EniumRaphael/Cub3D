/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:31:06 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/13 07:20:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "ft_string.h"
#include "ft_optional.h"
#include "ft_optional_types.h"
#include "mlx_functions.h"
#include <stdio.h>
#include <sys/types.h>

// steps:
// 1. load_file into a buffer
// 2. store the map while deleting trailing newlines
void *load_file(void *data)
{
	t_info	*info = (t_info *)data;
	char	*file = NULL;

	file = ft_fd_to_buff(info->map.fd);
	if (file == NULL)
		return (info->last_error = ERROR_READ_FILE, NULL);
	info->map.fraw = ft_split(file, '\n');
	if (info->map.fraw == NULL)
		return (info->last_error = ERROR_MALLOC, NULL);
	ft_free((void **)&file);
	info->last_error = NO_ERROR;
	return (info);
}

bool is_identifier(const char *str, const char *id_str[4])
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (ft_strstart_with(str, id_str[i]))
			return (true);
		i++;
	}
	return (false);
}

bool load_texture(t_info *info, const char *str)
{
	const char	*id_str[4] = {"NO", "SO", "WE", "EA"};
	size_t		i;
	t_texture	texture;


	i = 0;
	while (i < 4)
	{
		if (ft_strstart_with(str, id_str[i]))
		{
			texture.path = ft_strtrim(str + ft_strlen(id_str[i]), " ");
			if (texture.path == NULL)
				return (info->last_error = ERROR_MALLOC, false);
			texture.img = mlx_xpm_file_to_image(info->mlx_ptr, texture.path, \
			&texture.width, &texture.height);
			if (texture.img == NULL)
				return (info->last_error = ERROR_MLX, false);
			info->map.texture[i] = texture;
			return (true);
		}
		i++;
	}
	return (false);
}

void *load_textures(void *data)
{
	const char	*id_str[4] = {"NO", "SO", "WE", "EA"};
	t_info	*info = (t_info *)data;
	size_t	i;

	while (info->map.fraw[i])
	{
		if (is_identifier(info->map.fraw[i], id_str) && \
		(load_texture(info, info->map.fraw[i]) == false))
				return (NULL);
		i++;
	}
	return (info);
}

void *load_bgs(void *data)
{
	t_info *info = (t_info *)data;

	info->last_error = ERROR_IMPLEM;
	return (NULL);
}

void *load_tiles(void *data)
{
	t_info *info = (t_info *)data;

	info->last_error = ERROR_IMPLEM;
	return (NULL);
}

void *traverse_map(void *data)
{
	t_info *info = (t_info *)data;

	info->last_error = ERROR_IMPLEM;
	return (NULL);
}

void parse_map(t_info *info)
{
	t_optional opt = {OPT_NONE, NULL};
	const t_data_tr_i function_list[] = {
		load_file,
		load_textures,
		load_bgs,
		load_tiles,
		traverse_map,
		NULL,
	};

	opt.val = info;
	opt.pres = OPT_SOME;
	info->map.path = info->cli_ctx.file;
	if (ft_optional_chain(&opt, function_list) == false)
		return (c3_perror(info), (void)0);
}
