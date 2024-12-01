/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:10:44 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 18:36:26 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parsing.h"

void	update_pos_i(t_player *player)
{
	player->pos_i.x = (int)player->pos.x;
	player->pos_i.y = (int)player->pos.y;
}

void	move_straight(t_info *data)
{
	t_tile	*tile_x;
	t_tile	*tile_y;

	tile_x = c3_get_cell(data->map.map, data->map.size, \
		(t_ipoint){(int)(data->player.pos.x + data->player.dir.x * MOVE_SPEED), \
		(int)data->player.pos.y});
	if (tile_x->tile_type == EMPTY)
		data->player.pos.x += data->player.dir.x * MOVE_SPEED;
	tile_y = c3_get_cell(data->map.map, data->map.size, \
		(t_ipoint){(int)data->player.pos.x, (int)(data->player.pos.y \
		+ data->player.dir.y * MOVE_SPEED)});
	if (tile_y->tile_type == EMPTY)
		data->player.pos.y += data->player.dir.y * MOVE_SPEED;
	update_pos_i(&data->player);
}

void	move_backward(t_info *data)
{
	t_tile	*tile_x;
	t_tile	*tile_y;

	tile_x = c3_get_cell(data->map.map, data->map.size, \
		(t_ipoint){(int)(data->player.pos.x - data->player.dir.x * MOVE_SPEED), \
		(int)data->player.pos.y});
	if (tile_x->tile_type == EMPTY)
		data->player.pos.x -= data->player.dir.x * MOVE_SPEED;
	tile_y = c3_get_cell(data->map.map, data->map.size, \
		(t_ipoint){(int)data->player.pos.x, (int)(data->player.pos.y \
		- data->player.dir.y * MOVE_SPEED)});
	if (tile_y->tile_type == EMPTY)
		data->player.pos.y -= data->player.dir.y * MOVE_SPEED;
	update_pos_i(&data->player);
}

void	move_left(t_info *data)
{
	t_dpoint	pplayer;
	t_tile		*tile_x;
	t_tile		*tile_y;

	pplayer.x = -data->player.dir.y;
	pplayer.y = data->player.dir.x;
	tile_x = c3_get_cell(data->map.map, data->map.size, \
		(t_ipoint){(int)(data->player.pos.x + pplayer.x * MOVE_SPEED), \
		(int)data->player.pos.y});
	if (tile_x->tile_type == EMPTY)
		data->player.pos.x += pplayer.x * MOVE_SPEED;
	tile_y = c3_get_cell(data->map.map, data->map.size, \
		(t_ipoint){(int)data->player.pos.x, (int)(data->player.pos.y + \
		pplayer.y * MOVE_SPEED)});
	if (tile_y->tile_type == EMPTY)
		data->player.pos.y += pplayer.y * MOVE_SPEED;
	update_pos_i(&data->player);
}

void	move_right(t_info *data)
{
	t_dpoint	pplayer;
	t_tile		*tile_x;
	t_tile		*tile_y;

	pplayer.x = -data->player.dir.y;
	pplayer.y = data->player.dir.x;
	tile_x = c3_get_cell(data->map.map, data->map.size, \
	(t_ipoint){(int)(data->player.pos.x - pplayer.x * MOVE_SPEED), \
		(int)data->player.pos.y});
	if (tile_x->tile_type == EMPTY)
		data->player.pos.x -= pplayer.x * MOVE_SPEED;
	tile_y = c3_get_cell(data->map.map, data->map.size, \
	(t_ipoint){(int)data->player.pos.x, (int)(data->player.pos.y - pplayer.y \
		* MOVE_SPEED)});
	if (tile_y->tile_type == EMPTY)
		data->player.pos.y -= pplayer.y * MOVE_SPEED;
	update_pos_i(&data->player);
}
