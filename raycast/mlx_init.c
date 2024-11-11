/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:53:42 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/11 20:11:11 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "mlx_functions.h"
#include "mlx_structs.h"
#include <stdlib.h>

int	_keyhook(int keycode, t_info *info)
{
	if (keycode == 53 || keycode == 65307)
		return (cleanup_info(info), EXIT_SUCCESS);
	return (0);
}

int	_redcross(t_info *info)
{
	return (cleanup_info(info), EXIT_SUCCESS);
}

t_win_list	*_init_mlx_window(t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_get_screen_size(info->mlx_ptr, &x, &y);
	return (mlx_new_window(info->mlx_ptr, x, y, "Miaou"));
}

int	init_mlx_env(t_info *info)
{
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		return (MLX_ERROR);
	info->win_ptr = _init_mlx_window(info);
	if (!info->win_ptr)
		return (MLX_ERROR);
	mlx_hook(info->win_ptr, 2, 1L << 0, _keyhook, info);
	mlx_hook(info->win_ptr, 17, 1L << 17, _redcross, info);
	mlx_loop(info->mlx_ptr);
	return (NO_ERROR);
}
