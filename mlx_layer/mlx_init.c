/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:53:42 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/12 06:19:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "mlx_functions.h"
#include "mlx_structs.h"

#include <stdlib.h>
#include <X11/keysym.h>

int	c3_frame_update(void *inf_ptr);

int	c3_keyhook(int keycode, t_info *info)
{
	if (keycode == XK_Escape || keycode == 65307)
		return (mlx_loop_end(info->mlx_ptr), EXIT_SUCCESS);
	/* move player w keys and call to redraw screen */
	return (EXIT_SUCCESS);
}

int	c3_redcross(t_info *info)
{
	return (mlx_loop_end(info->mlx_ptr), EXIT_SUCCESS);
}

t_win_list	*c3_init_mlx_window(t_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_get_screen_size(info->mlx_ptr, &x, &y);
	return (mlx_new_window(info->mlx_ptr, x, y, "C3D"));
}

int	init_mlx_env(t_info *info)
{
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		return (ERROR_MLX);
	info->win_ptr = c3_init_mlx_window(info);
	if (!info->win_ptr)
		return (ERROR_MLX);
	mlx_hook(info->win_ptr, KeyPress, KeyPressMask, c3_keyhook, info);
	mlx_hook(info->win_ptr, DestroyNotify, StructureNotifyMask, c3_redcross, info);
	mlx_loop_hook(info->mlx_ptr, c3_frame_update, info);
	return (NO_ERROR);
}
