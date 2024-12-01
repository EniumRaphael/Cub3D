/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:02:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 18:57:25 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"

#include "mlx_functions.h"
#include "ft_string.h"
#include "ft_math.h"

#include <math.h>
#include <unistd.h>

void	set_step(t_ipoint *step, t_dpoint raydir);
void	set_side_dist(t_dpoint *side_dist, t_dpoint *tb, t_ipoint pos_i);

/// line 33: normalize draw_start and draw_end
void	draw_(int side, double perpWallDist, t_ipoint step, int x, t_info *data)
{
	const int	line_height = (int)(data->screen_size.y / perpWallDist) \
		* cos(deg2rad(FOV / 2));
	int			draw_start;
	int			draw_end;
	int			color;

	draw_start = -line_height / 2 + data->screen_size.y / 2;
	draw_end = line_height / 2 + data->screen_size.y / 2;
	draw_start = ft_clamp(draw_start, 0, data->screen_size.y - 1);
	draw_end = ft_clamp(draw_end, 0, data->screen_size.y - 1);
	color = get_cl(side, step);
	while (draw_start < draw_end)
		my_mlx_pixel_put(data, x, draw_start++, color);
}

void	search_hit(t_dpoint *sideDist, t_dpoint deltaDist, t_ipoint *pos_i, \
		t_ipoint step, void *_data[2])
{
	int		*side;
	t_info	*data;

	side = (int *)_data[1];
	data = (t_info *)_data[0];
	while (true)
	{
		if (sideDist->x < sideDist->y)
		{
			sideDist->x += deltaDist.x;
			pos_i->x += step.x;
			*side = 0;
		}
		else
		{
			sideDist->y += deltaDist.y;
			pos_i->y += step.y;
			*side = 1;
		}
		if ((*c3_get_cell(data->map.map, data->map.size, *pos_i))
			.tile_type != EMPTY)
			return ;
	}
}

void	column_handler(t_ipoint pos_i, t_dpoint ray_dir, t_info *data, int x)
{
	t_dpoint	side_dist;
	t_dpoint	delta_dist;
	double		perp_wall_dist;
	t_ipoint	step;
	int			side;

	delta_dist = (t_dpoint){fabs(1 / ray_dir.x), fabs(1 / ray_dir.y)};
	set_step(&step, ray_dir);
	set_side_dist(&side_dist, (t_dpoint[]){ray_dir, data->player.pos, \
		delta_dist}, pos_i);
	search_hit(&side_dist, delta_dist, &pos_i, step, (void *[]){data, &side});
	if (side == 0)
		perp_wall_dist = (pos_i.x - data->player.pos.x + \
			(double)(1 - step.x) / 2) / ray_dir.x;
	else
		perp_wall_dist = (pos_i.y - data->player.pos.y + \
			(double)(1 - step.y) / 2) / ray_dir.y;
	draw_(side, perp_wall_dist, step, x, data);
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

// Return 42 is irrelevant check mlx_loop to see that mlx doesn't care for the 
//		return of the function... 
//		(Why 'int (*)(void*)' when you dont use the int)
//
// This function is called each time the mlx loops over the mlx pointer in 
//		mlx_loop. here we do calc on time since last frame and player position 
//		to know if we need to re-draw the screen. if yes call raph function for
//		calc.
// The need to redraw can also be expressed in the diferent key_pressed 
//		functions, I would recomend to make a bool field for that in the info
//		struct.
// As a pure artefact of using mlx this function will likely be mooved to 
//		mlx_layer in the final repo.
int	c3_frame_update(void *inf_ptr)
{
	t_info	*info;

	info = inf_ptr;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	return (EXIT_SUCCESS);
}
