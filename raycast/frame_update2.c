/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:55:11 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/16 09:43:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "ft_string.h"

#include <unistd.h>

void	draw_bg(t_info *data)
{
	t_ipoint	temp;
	int			switch_point;
	int			color;

	ft_bzero(&temp, sizeof(t_ipoint));
	switch_point = data->screen_size.y / 2;
	color = data->map.bg_colors[BG_SKY].color;
	while (temp.y < data->screen_size.y)
	{
		temp.x = 0;
		while (temp.x < data->screen_size.x)
		{
			my_mlx_pixel_put(data, temp.x, temp.y, color);
			temp.x++;
		}
		temp.y++;
		if (temp.y >= switch_point)
			color = data->map.bg_colors[BG_FLR].color;
	}
}

void	set_step(t_ipoint *step, t_dpoint raydir)
{
	if (raydir.x < 0)
		step->x = -1;
	else
		step->x = 1;
	if (raydir.y < 0)
		step->y = -1;
	else
		step->y = 1;
}

void	set_side_dist(t_dpoint *side_dist, t_dpoint *tb, t_ipoint pos_i)
{
	t_dpoint	ray_dir;
	t_dpoint	pos;
	t_dpoint	delta_dist;

	ray_dir = tb[0];
	pos = tb[1];
	delta_dist = tb[2];
	if (ray_dir.x < 0)
		side_dist->x = (pos.x - pos_i.x) * delta_dist.x;
	else
		side_dist->x = (pos_i.x + 1.0 - pos.x) * delta_dist.x;
	if (ray_dir.y < 0)
		side_dist->y = (pos.y - pos_i.y) * delta_dist.y;
	else
		side_dist->y = (pos_i.y + 1.0 - pos.y) * delta_dist.y;
}
