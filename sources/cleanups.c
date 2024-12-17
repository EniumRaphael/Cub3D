/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:11:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/17 17:23:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "ft_string.h"
#include "mlx.h"

static void	cleanup_cli(t_cli *cli_ctx)
{
	if (cli_ctx->file)
		ft_free((void **)&cli_ctx->file);
}

static void	cleanup_map(t_map *map)
{
	if (map->fd)
		(close(map->fd), map->fd = 0);
	if (map->fraw)
		(ft_free_2d((void **)map->fraw), map->fraw = NULL);
	if (map->map)
		ft_free((void **)&map->map);
}

static void	cleanup_mlx(t_info *info)
{
	size_t	i;

	i = 0;
	if (!info->mlx_ptr)
		return ;
	if (info->win_ptr)
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	while (i < sizeof(info->map.texture) / sizeof(info->map.texture[0]))
	{
		if (info->map.texture[i].img)
			mlx_destroy_image(info->mlx_ptr, info->map.texture[i].img);
		if (info->map.texture[i++].path)
			ft_free((void **)&info->map.texture[i - 1].path);
	}
	i = 0;
	if (info->camera.screen_buff)
		mlx_destroy_image(info->mlx_ptr, info->camera.screen_buff);
	mlx_destroy_display(info->mlx_ptr);
	ft_free((void **)&info->mlx_ptr);
}

void	cleanup_info(t_info *info)
{
	cleanup_cli(&info->cli_ctx);
	cleanup_map(&info->map);
	cleanup_mlx(info);
}
