/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:25:45 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/02 17:54:04 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_functions.h"

t_img	*mlx_load_image(t_info *info, char *path)
{
	t_img	*image;
	int		size;

	size = TILES_SIZE;
	image = mlx_xpm_file_to_image(info->mlx_ptr, path, &size, &size);
	if (!image)
		return (NULL);
	return (image);
}

bool	mlx_load_all_textures(t_info *info)
{
	size_t	i;

	i = 0;
	info->map.texture[0] = mlx_load_image(info, "../textures/a.xpm");
	info->map.texture[1] = mlx_load_image(info, "../textures/b.xpm");
	info->map.texture[2] = mlx_load_image(info, "../textures/sandy_32.xpm");
	info->map.texture[3] = mlx_load_image(info, "../textures/cobblestone_32.xpm");
	
	while (i < 4)
	{
		if (!info->map.texture[i])
			return (false);
		i++;
	}
	return (true);
}
