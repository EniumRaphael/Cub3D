/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:11:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/11 21:30:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "ft_string.h"

static void	cleanup_cli(t_cli *cli_ctx)
{
	if (cli_ctx->file)
		ft_free((void **)&cli_ctx->file);
}

static void	cleanup_map(t_map *map)
{
	(void)map;
}

static void	cleanup_mlx(t_info *info)
{
	(void)info;
}

void	cleanup_info(t_info *info)
{
	cleanup_cli(&info->cli_ctx);
	cleanup_map(&info->map);
	cleanup_mlx(info);
}
