/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:12:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/16 14:16:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"

#include <X11/keysym.h>
#include <sys/types.h>

static void	update_pos_i(t_player *player)
{
	player->pos_i.x = (int)player->pos.x;
	player->pos_i.y = (int)player->pos.y;
}

int	displacement_hook(t_info *data)
{
	data->redraw = true;
	update_pos_i(&data->player);
	if (data->kb.forward && !data->kb.backward)
		move_straight(data);
	if (data->kb.backward && !data->kb.forward)
		move_backward(data);
	if (data->kb.left && !data->kb.right)
		move_left(data);
	if (data->kb.right && !data->kb.left)
		move_right(data);
	if (data->kb.l_left && !data->kb.l_right)
		look_left(data);
	if (data->kb.l_right && !data->kb.l_left)
		look_right(data);
	update_pos_i(&data->player);
	return (0);
}
