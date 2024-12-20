/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:46:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/20 14:47:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parsing.h"

#include "ft_string.h"

#include "mlx.h"
#include <stdbool.h>
#include <stdio.h>

static bool	no_leaks(t_info *inf, t_texture *texture, enum e_error error)
{
	if (texture->img != NULL)
		mlx_destroy_image(inf->mlx_ptr, texture->img);
	if (texture->path != NULL)
		free(texture->path);
	sv_errno(inf, error);
	return (false);
}

bool	load_texture(t_info *info, const char *str, const char **id_str)
{
	size_t		i;
	t_texture	texture;

	i = 0;
	ft_bzero(&texture, sizeof(t_texture));
	while (i < 4)
	{
		if (ft_strstart_with(str, id_str[i]))
		{
			if (info->map.texture[i].img != NULL)
				return (sv_errno(info, ERROR_PARSE_ALREADY_SET), false);
			texture.path = ft_strtrim(str + ft_strlen(id_str[i]), " \t");
			if (texture.path == NULL)
				return (sv_errno(info, ERROR_MALLOC), false);
			if (ft_strend_with(texture.path, ".xpm") == false)
				return (no_leaks(info, &texture, ERROR_TEXTURE_FORMAT));
			texture.img = mlx_xpm_file_to_image(info->mlx_ptr, texture.path,
					&texture.width, &texture.height);
			if (texture.img == NULL)
				return (no_leaks(info, &texture, ERROR_MLX));
			return (info->map.texture[i] = texture, true);
		}
		i++;
	}
	return (false);
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
		if (is_identifier(info->map.fraw[i], id_str) && load_texture(info,
				info->map.fraw[i], id_str) == false)
			return (NULL);
		i++;
	}
	i = 0;
	errno = 0;
	while (i < sizeof(info->map.texture) / sizeof(info->map.texture[0]))
	{
		if (info->map.texture[i].img == NULL)
			return (sv_errno(info, ERROR_TEXTURE_MISSING), NULL);
		i++;
	}
	return (info);
}
