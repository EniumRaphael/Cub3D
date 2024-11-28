/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:09:00 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/28 12:09:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_math.h"
#include "minilibx-linux/mlx.h"
#include <math.h>
#include <X11/X.h>

#include "./test.h"

const int	g_worldMap[MAP_WIDTH][MAP_HEIGHT] = { \
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} \
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	uint	*dst;

	x *= data->bits_per_pixel / 8;
	dst = (uint *)(data->addr + (y * data->line_length + x));
	*dst = color;
}

double	deg2rad(int deg)
{
	return (deg * M_PI / 180);
}

void	rotate_plane(t_2dpoint *plane, double angle)
{
	double	old_plane_x;
	double	old_plane_y;

	old_plane_x = (*plane).x;
	old_plane_y = (*plane).y;
	plane->x = plane->x * cos(angle) - plane->y * sin(angle);
	plane->y = old_plane_x * sin(angle) + plane->y * cos(angle);
}

void	move_straight(t_data *data)
{
	if (!g_worldMap[\
		(int)(data->pos.x + data->dir.x * MOVE_SPEED)][(int)data->pos.y])
		data->pos.x += data->dir.x * MOVE_SPEED;
	if (!g_worldMap[\
		(int)data->pos.x][(int)(data->pos.y + data->dir.y * MOVE_SPEED)])
		data->pos.y += data->dir.y * MOVE_SPEED;
}

void	move_backward(t_data *data)
{
	if (!g_worldMap[\
		(int)(data->pos.x - data->dir.x * MOVE_SPEED)][(int)data->pos.y])
		data->pos.x -= data->dir.x * MOVE_SPEED;
	if (!g_worldMap[\
		(int)data->pos.x][(int)(data->pos.y - data->dir.y * MOVE_SPEED)])
		data->pos.y -= data->dir.y * MOVE_SPEED;
}

void	move_left(t_data *data)
{
	double	pdir_x;
	double	pdir_y;

	pdir_x = -data->dir.y;
	pdir_y = data->dir.x;
	if (!g_worldMap[(int)(data->pos.x + pdir_x * MOVE_SPEED)][(int)data->pos.y])
		data->pos.x -= pdir_x * MOVE_SPEED;
	if (!g_worldMap[(int)data->pos.x][(int)(data->pos.y - pdir_y * MOVE_SPEED)])
		data->pos.y -= pdir_y * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	double	pdir_x;
	double	pdir_y;

	pdir_x = -data->dir.y;
	pdir_y = data->dir.x;
	if (!g_worldMap[(int)(data->pos.x - pdir_x * MOVE_SPEED)][(int)data->pos.y])
		data->pos.x += pdir_x * MOVE_SPEED;
	if (!g_worldMap[(int)data->pos.x][(int)(data->pos.y + pdir_y * MOVE_SPEED)])
		data->pos.y += pdir_y * MOVE_SPEED;
}

void	look_left(t_data *data)
{
	rotate_plane(&data->dir, ROT_SPEED);
	rotate_plane(&data->plane, ROT_SPEED);
}

void	look_right(t_data *data)
{
	rotate_plane(&data->dir, -ROT_SPEED);
	rotate_plane(&data->plane, -ROT_SPEED);
}
 
int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exit(0);
	if (keycode == XK_w)
		move_straight(data);
	if (keycode == XK_s)
		move_backward(data);
	if (keycode == XK_a)
		move_right(data);
	if (keycode == XK_d)
		move_left(data);
	if (keycode == XK_Left)
		look_left(data);
	if (keycode == XK_Right)
		look_right(data);
	return (0);
}

int get_cl(int side, t_2ipoint step)
{
	int color;

	if (side == 0 && step.x > 0)
		color = 0x00FF0000;
	else if (side == 0 && step.x < 0)
		color = 0x0000FF00;
	else if (side == 1 && step.y > 0)
		color = 0x000000FF;
	else
		color = 0x00FFFF00;
	return (color);
}

void draw_(int side, double perpWallDist, t_2ipoint step, int x, t_data *data)
{
	const int	lineHeight = (int)(WINDOW_HEIGHT / perpWallDist) * cos(deg2rad(FOV/ 2));
	int			drawStart;
	int			drawEnd;
	int			color;

	drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
	drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
	// normalize drawStart and drawEnd
	drawStart = ft_clamp(drawStart, 0, WINDOW_HEIGHT - 1);
	drawEnd = ft_clamp(drawEnd, 0, WINDOW_HEIGHT - 1);
	color = get_cl(side, step);
	while (drawStart < drawEnd)
		my_mlx_pixel_put(data, x, drawStart++, color);
}


void search_hit(t_2dpoint *sideDist, t_2dpoint deltaDist, t_2ipoint *map, t_2ipoint step, int *side)
{
	while (true) {
		if (sideDist->x < sideDist->y) {
			sideDist->x += deltaDist.x;
			map->x += step.x;
			*side = 0;
		} else {
			sideDist->y += deltaDist.y;
			map->y += step.y;
			*side = 1;
		}

		if (g_worldMap[map->x][map->y] > 0)
			return ;
	}
}

void static set_step(t_2ipoint *step, t_2dpoint raydir)
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

void static set_side_dist(t_2dpoint *sideDist, t_2dpoint *tb, t_2ipoint map)
{
	t_2dpoint rayDir = tb[0];
	t_2dpoint pos = tb[1];
	t_2dpoint deltaDist = tb[2];

	if (rayDir.x < 0)
		sideDist->x = (pos.x - map.x) * deltaDist.x;
	else 
		sideDist->x = (map.x + 1.0 - pos.x) * deltaDist.x;
	if (rayDir.y < 0)
		sideDist->y = (pos.y - map.y) * deltaDist.y;
	else
		sideDist->y = (map.y + 1.0 - pos.y) * deltaDist.y;
}

void	column_handler(t_2ipoint map, t_2dpoint rayDir, t_data *data, int x)
{
	t_2dpoint	sideDist;
	t_2dpoint	deltaDist;
	double		perpWallDist;
	t_2ipoint	step;
	int			side;

	deltaDist = (t_2dpoint){fabs(1 / rayDir.x), fabs(1 / rayDir.y)};
	set_step(&step, rayDir);
	set_side_dist(&sideDist, (t_2dpoint[]){rayDir, data->pos, deltaDist}, map);
	search_hit(&sideDist, deltaDist, &map, step, &side);
	if (side == 0)
		perpWallDist = (map.x - data->pos.x + (double)(1 - step.x) / 2)
			/ rayDir.x;
	else
		perpWallDist = (map.y - data->pos.y + (double)(1 - step.y) / 2)
			/ rayDir.y;
	draw_(side, perpWallDist, step, x, data);
}

int	render_frame(t_data *data)
{
	double cameraX;
	double coef;

	coef = 2 * tan(deg2rad(FOV) / 2) / (double)WINDOW_WIDTH;
	ft_bzero(data->addr, WINDOW_WIDTH * WINDOW_HEIGHT * data->bits_per_pixel / 8);
	for(int x = 0; x < WINDOW_WIDTH; x++)
	{
		cameraX = x * coef - 1;
		column_handler((t_2ipoint){(int)data->pos.x, (int)data->pos.y},
			(t_2dpoint){data->dir.x + data->plane.x * cameraX, data->dir.y + data->plane.y * cameraX},
			data, x);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Raycaster");
	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	// player position
	//
	// used to get player position in the map
	data.pos.x = 22;
	data.pos.y = 12;
	// player look direction
	//
	// used to get player look direction vector
	data.dir.x = -1;
	data.dir.y = 0;
	// plane perpendicular to look direction
	// 
	// used to get player camera plane (aka projected screen in front of the 
	// player for ray intersection)
	// the length of the camera plane is 2 * tan(fov / 2) * 1
	// where fov is the field of view of the camera
	data.plane.x = 0;
	data.plane.y = \
		2 * tan(deg2rad(FOV) / 2);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_hook, &data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
