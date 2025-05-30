/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:53:42 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/17 17:18:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"

#include "mlx.h"
#include "mlx_structs.h"

#include "ft_math.h"

#include <stdbool.h>

#include <stdlib.h>
#include <X11/keysym.h>

int	c3_keyhook(int keycode, t_info *info)
{
	if (keycode == XK_Escape || keycode == 65307)
		return (mlx_loop_end(info->mlx_ptr), EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	c3_redcross(t_info *info)
{
	return (mlx_loop_end(info->mlx_ptr), EXIT_SUCCESS);
}

t_win_list	*c3_init_mlx_window(t_info *info)
{
	mlx_get_screen_size(info->mlx_ptr, \
		&info->screen_size.x, &info->screen_size.y);
	info->screen_size.x *= WIN_COEF;
	info->screen_size.y *= WIN_COEF;
	ft_clamp(info->screen_size.x, 0, 1920);
	ft_clamp(info->screen_size.y, 0, 1080);
	return (\
	mlx_new_window(info->mlx_ptr, info->screen_size.x, info->screen_size.y, \
				WIN_TITLE));
}

int	init_mlx_env(t_info *info)
{
	info->win_ptr = c3_init_mlx_window(info);
	if (!info->win_ptr)
		return (sv_errno(info, ERROR_MLX), ERROR_MLX);
	mlx_hook(info->win_ptr, KeyPress, KeyPressMask, keypress_feature, info);
	mlx_hook(info->win_ptr, KeyRelease, KeyReleaseMask, keyrelease_feature, \
		info);
	mlx_hook(info->win_ptr, DestroyNotify, StructureNotifyMask, \
		c3_redcross, info);
	mlx_loop_hook(info->mlx_ptr, (int (*)())shelves_launch, info);
	return (NO_ERROR);
}
