/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:02:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/16 14:51:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"

#include "mlx_functions.h"
#include "ft_string.h"

#include <math.h>
#include <unistd.h>

void	search_hit(t_dpoint delta_dist, t_ipoint *pos_i, t_ipoint step, \
	void *_data[3])
{
	int			*side;
	t_info		*data;
	t_dpoint	*side_dist;

	side = (int *)_data[1];
	data = (t_info *)_data[0];
	side_dist = (t_dpoint *)_data[2];
	while (true)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist.x;
			pos_i->x += step.x;
			*side = 0;
		}
		else
		{
			side_dist->y += delta_dist.y;
			pos_i->y += step.y;
			*side = 1;
		}
		if ((*c3_get_cell(data->map.map, data->map.size, *pos_i))
			.tile_type != EMPTY)
			return ;
	}
}

// t_dpoint prep_distoff ->
//  x - perpwall_dist
//  y - wall_off
void	column_handler(t_ipoint pos_i, t_dpoint ray_dir, t_info *data, int x)
{
	t_dpoint	side_dist;
	t_dpoint	delta_dist;
	t_dpoint	perp_distoff;
	t_ipoint	step;
	int			side;

	delta_dist = (t_dpoint){fabs(1 / ray_dir.x), fabs(1 / ray_dir.y)};
	set_step(&step, ray_dir);
	set_side_dist(&side_dist, (t_dpoint[]){ray_dir, data->player.pos, \
		delta_dist}, pos_i);
	search_hit(delta_dist, &pos_i, step, (void *[]){data, &side, &side_dist});
	if (side == 0)
		perp_distoff.x = (pos_i.x - data->player.pos.x + \
			(double)(1 - step.x) / 2) / ray_dir.x;
	else
		perp_distoff.x = (pos_i.y - data->player.pos.y + \
			(double)(1 - step.y) / 2) / ray_dir.y;
	perp_distoff.y = data->player.pos.x + perp_distoff.x * ray_dir.x;
	if (side == 0)
		perp_distoff.y = data->player.pos.y + perp_distoff.x * ray_dir.y;
	perp_distoff.y -= floor(perp_distoff.y);
	draw_((int []){side, x}, (double []){perp_distoff.x, perp_distoff.y}, \
	step, data);
}

int	render_frame(t_info *data)

{
	double	camera_x;
	double	coef;
	int		x;

	x = 0;
	coef = 2 * tan(deg2rad(FOV) / 2) / (double)data->screen_size.x;
	ft_bzero(data->camera.img_addr, data->screen_size.x * data->screen_size.y \
	* (data->camera.bpp / 8));
	draw_bg(data);
	while (x < data->screen_size.x)
	{
		camera_x = x * coef - 1;
		column_handler(data->player.pos_i, (t_dpoint){\
			data->player.dir.x + data->player.plane.x * camera_x, \
			data->player.dir.y + data->player.plane.y * camera_x}, \
			data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->camera.screen_buff, 0, 0);
	return (0);
}
