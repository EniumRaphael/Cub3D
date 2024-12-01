/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:46:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 17:53:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "cub3d_parsing.h"

#include "ft_string.h"

#include "mlx_functions.h"
#include <stdbool.h>

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
			texture.img = mlx_xpm_file_to_image(info->mlx_ptr, texture.path,
					&texture.width, &texture.height);
			if (texture.img == NULL)
				return (info->errno_state = errno, info->last_error = ERROR_MLX,
					false);
			return (info->map.texture_[i] = texture, true);
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
	return (info);
}
