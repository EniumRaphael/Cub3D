/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:02:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/29 17:01:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"

#include "mlx_functions.h"
#include "ft_string.h"
#include "ft_math.h"

#include <math.h>
#include <unistd.h>

void draw_(int side, double perpWallDist, t_ipoint step, int x, t_info *data)
{
	const int	lineHeight = (int)(data->screen_size.y / perpWallDist) * cos(deg2rad(FOV/ 2));
	int			drawStart;
	int			drawEnd;
	int			color;

	drawStart = -lineHeight / 2 + data->screen_size.y / 2;
	drawEnd = lineHeight / 2 + data->screen_size.y / 2;
	// normalize drawStart and drawEnd
	drawStart = ft_clamp(drawStart, 0, data->screen_size.y - 1);
	drawEnd = ft_clamp(drawEnd, 0, data->screen_size.y - 1);
	color = get_cl(side, step);
	while (drawStart < drawEnd)
		my_mlx_pixel_put(data, x, drawStart++, color);
}

void search_hit(t_dpoint *sideDist, t_dpoint deltaDist, t_ipoint *pos_i, t_ipoint step, void *_data[2])
{
	int *side = (int *)_data[1];
	t_info *data = (t_info *)_data[0];

	while (true) {
		if (sideDist->x < sideDist->y) {
			sideDist->x += deltaDist.x;
			pos_i->x += step.x;
			*side = 0;
		} else {
			sideDist->y += deltaDist.y;
			pos_i->y += step.y;
			*side = 1;
		}
		
		if (data->map.size.x < 0 || data->map.size.y < 0 ||
		data->map.size.x > 100 || data->map.size.y > 100)
			exit (EXIT_FAILURE);

		if ((*c3_get_cell(data->map.map, data->map.size, *pos_i))
			.tile_type != EMPTY)
			return ;
	}
}

static void set_step(t_ipoint *step, t_dpoint raydir)
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

static void set_side_dist(t_dpoint *sideDist, t_dpoint *tb, t_ipoint pos_i)
{
	t_dpoint rayDir = tb[0];
	t_dpoint pos = tb[1];
	t_dpoint deltaDist = tb[2];

	if (rayDir.x < 0)
		sideDist->x = (pos.x - pos_i.x) * deltaDist.x;
	else 
		sideDist->x = (pos_i.x + 1.0 - pos.x) * deltaDist.x;
	if (rayDir.y < 0)
		sideDist->y = (pos.y - pos_i.y) * deltaDist.y;
	else
		sideDist->y = (pos_i.y + 1.0 - pos.y) * deltaDist.y;
}

void	column_handler(t_ipoint pos_i, t_dpoint rayDir, t_info *data, int x)
{
	t_dpoint	sideDist;
	t_dpoint	deltaDist;
	double		perpWallDist;
	t_ipoint	step;
	int			side;

	deltaDist = (t_dpoint){fabs(1 / rayDir.x), fabs(1 / rayDir.y)};
	set_step(&step, rayDir);
	set_side_dist(&sideDist, (t_dpoint[]){rayDir, data->player.pos, deltaDist}, pos_i);
	search_hit(&sideDist, deltaDist, &pos_i, step, (void *[]){data, &side});
	if (side == 0)
		perpWallDist = (pos_i.x - data->player.pos.x + (double)(1 - step.x) / 2)
			/ rayDir.x;
	else
		perpWallDist = (pos_i.y - data->player.pos.y + (double)(1 - step.y) / 2)
			/ rayDir.y;
	draw_(side, perpWallDist, step, x, data);
}

int	render_frame(t_info *data)
{
	double camera_x;
	double coef;

	coef = 2 * tan(deg2rad(FOV) / 2) / (double)data->screen_size.x;
	ft_bzero(data->camera.img_addr, data->screen_size.x * data->screen_size.y * (data->camera.bpp / 8));
	for(int x = 0; x < data->screen_size.x; x++)
	{
		camera_x = x * coef - 1;
		column_handler(data->player.pos_i,
			(t_dpoint){
				data->player.dir.x + data->player.plane.x * camera_x, 
				data->player.dir.y + data->player.plane.y * camera_x},
			data, x);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->camera.screen_buff, 0, 0);
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
int c3_frame_update(void *inf_ptr)
{
	t_info *info;

	info = inf_ptr;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
//	ft_putendl_fd("update called\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
