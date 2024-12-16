/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:40:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/16 14:41:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "mlx_functions.h"

#include <stdbool.h>
#include <X11/keysym.h>

void	set_kb(t_keyboard *kb, int keycode)
{
	if (keycode == XK_w)
		kb->forward = true;
	if (keycode == XK_s)
		kb->backward = true;
	if (keycode == XK_a)
		kb->left = true;
	if (keycode == XK_d)
		kb->right = true;
	if (keycode == XK_Right)
		kb->l_right = true;
	if (keycode == XK_Left)
		kb->l_left = true;
}

void	unset_kb(t_keyboard *kb, int keycode)
{
	if (keycode == XK_w)
		kb->forward = false;
	if (keycode == XK_s)
		kb->backward = false;
	if (keycode == XK_a)
		kb->left = false;
	if (keycode == XK_d)
		kb->right = false;
	if (keycode == XK_Left)
		kb->l_left = false;
	if (keycode == XK_Right)
		kb->l_right = false;
}

int	keypress_feature(int keycode, t_info *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	set_kb(&data->kb, keycode);
	return (0);
}

int	keyrelease_feature(int keycode, t_info *data)
{
	unset_kb(&data->kb, keycode);
	return (0);
}
