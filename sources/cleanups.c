/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:11:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/12 05:49:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "ft_string.h"
#include "mlx_functions.h"

static void	cleanup_cli(t_cli *cli_ctx)
{
	if (cli_ctx->file)
		ft_free((void **)&cli_ctx->file);
}

static void	cleanup_map(t_map *map)
{
	if (map->fd)
		(close(map->fd), map->fd = 0);
}

static void	cleanup_mlx(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_display(info->mlx_ptr);
	if (info->mlx_ptr)
		ft_free((void **)&info->mlx_ptr);
}

void	cleanup_info(t_info *info)
{
	cleanup_cli(&info->cli_ctx);
	cleanup_map(&info->map);
	cleanup_mlx(info);
}
