/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:12:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 18:46:32 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"

#include "mlx_functions.h"

#include "ft_char.h"
#include <X11/keysym.h>
#include <stdio.h>

int	key_hook(int keycode, t_info *data)
{
	if (ft_isalpha(keycode))
		printf("Event detected: %d\t(%c)\n", keycode, keycode);
	else if (keycode == 65361)
		printf("Event detected: %d\t(Left Arrow)\n", keycode);
	else if (keycode == 65363)
		printf("Event detected: %d\t(Right Arrow)\n", keycode);
	else if (keycode == 65307)
		printf("Event detected: %d\t(Echap)\n", keycode);
	else
		printf("Event detected: %d\n", keycode);
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	if (keycode == XK_w)
		move_straight(data);
	if (keycode == XK_s)
		move_backward(data);
	if (keycode == XK_a)
		move_left(data);
	if (keycode == XK_d)
		move_right(data);
	if (keycode == XK_Left)
		look_left(data);
	if (keycode == XK_Right)
		look_right(data);
	return (0);
}
