/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:09:00 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/01 17:25:59 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	worldMap[MAP_WIDTH][MAP_HEIGHT] = {\
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, \
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} \
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	move_straight(t_data *data)
{
	if (!worldMap[\
		(int)(data->pos_x + data->dir_x * MOVE_SPEED)][(int)data->pos_y])
		data->pos_x += data->dir_x * MOVE_SPEED;
	if (!worldMap[\
		(int)data->pos_x][(int)(data->pos_y + data->dir_y * MOVE_SPEED)])
		data->pos_y += data->dir_y * MOVE_SPEED;
}

void	move_backward(t_data *data)
{
	if (!worldMap[\
		(int)(data->pos_x - data->dir_x * MOVE_SPEED)][(int)data->pos_y])
		data->pos_x -= data->dir_x * MOVE_SPEED;
	if (!worldMap[\
		(int)data->pos_x][(int)(data->pos_y - data->dir_y * MOVE_SPEED)])
		data->pos_y -= data->dir_y * MOVE_SPEED;
}

void	move_left(t_data *data)
{
	double	perp_dir_x;
	double	perp_dir_y;

	perp_dir_x = -data->dir_y;
	perp_dir_y = data->dir_x;
	if (!worldMap[\
		(int)(data->pos_x + perp_dir_x * MOVE_SPEED)][(int)data->pos_y])
		data->pos_x -= perp_dir_x * MOVE_SPEED;
	if (!worldMap[\
		(int)data->pos_x][(int)(data->pos_y - perp_dir_y * MOVE_SPEED)])
		data->pos_y -= perp_dir_y * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	double	perp_dir_x;
	double	perp_dir_y;

	perp_dir_x = -data->dir_y;
	perp_dir_y = data->dir_x;
	if (!worldMap[\
		(int)(data->pos_x - perp_dir_x * MOVE_SPEED)][(int)data->pos_y])
		data->pos_x += perp_dir_x * MOVE_SPEED;
	if (!worldMap[\
		(int)data->pos_x][(int)(data->pos_y + perp_dir_y * MOVE_SPEED)])
		data->pos_y += perp_dir_y * MOVE_SPEED;
}

void	look_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(ROT_SPEED) - data->dir_y * sin(ROT_SPEED);
	data->dir_y = old_dir_x * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
	data->plane_x = data->plane_x * cos(ROT_SPEED) \
				- data->plane_y * sin(ROT_SPEED);
	data->plane_y = old_plane_x * sin(ROT_SPEED) \
				+ data->plane_y * cos(ROT_SPEED);
}

void	look_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(-ROT_SPEED) - data->dir_y * sin(-ROT_SPEED);
	data->dir_y = old_dir_x * sin(-ROT_SPEED) + data->dir_y * cos(-ROT_SPEED);
	data->plane_x = data->plane_x * cos(-ROT_SPEED) \
				- data->plane_y * sin(-ROT_SPEED);
	data->plane_y = old_plane_x * sin(-ROT_SPEED) \
				+ data->plane_y * cos(-ROT_SPEED);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 119)
		move_straight(data);
	if (keycode == 115)
		move_backward(data);
	if (keycode == 97)
		move_right(data);
	if (keycode == 100)
		move_left(data);
	if (keycode == 65361)
		look_left(data);
	if (keycode == 65363)
		look_right(data);
	return (0);
}

int	render_frame(t_data *data)
{
	int	y;
	int x;

	y = 0;
	while (y < data->screen_y)
	{
		x = 0;
		while (x < data->screen_x)
		{
			my_mlx_pixel_put(data, x, y, 0x00000000);
			x++;
		}
		y++;
	}

	for(int x = 0; x < data->screen_x; x++)
	{
		double cameraX = 2 * x / (double)data->screen_x - 1;
		double rayDirX = data->dir_x + data->plane_x * cameraX;
		double rayDirY = data->dir_y + data->plane_y * cameraX;

		int mapX = (int)data->pos_x;
		int mapY = (int)data->pos_y;

		double sideDistX, sideDistY;
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		int stepX, stepY;
		int hit = 0;
		int side;

		if (rayDirX < 0) {
			stepX = -1;
			sideDistX = (data->pos_x - mapX) * deltaDistX;
		} else {
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->pos_x) * deltaDistX;
		}
		if (rayDirY < 0) {
			stepY = -1;
			sideDistY = (data->pos_y - mapY) * deltaDistY;
		} else {
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->pos_y) * deltaDistY;
		}

		while (hit == 0) {
			if (sideDistX < sideDistY) {
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			} else {
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (mapX - data->pos_x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - data->pos_y + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(data->screen_y / perpWallDist);
		int drawStart = -lineHeight / 2 + data->screen_y / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + data->screen_y / 2;
		if(drawEnd >= data->screen_y) drawEnd = data->screen_y - 1;

		int color;
		if (side == 0 && stepX > 0)
			color = 0x00FF0000;
		else if (side == 0 && stepX < 0)
			color = 0x0000FF00;
		else if (side == 1 && stepY > 0)
			color = 0x000000FF;
		else
			color = 0x00FFFF00;

		for(int y = drawStart; y < drawEnd; y++)
			my_mlx_pixel_put(data, x, y, color);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx = mlx_init();
	mlx_get_screen_size(data.mlx, &data.screen_x, &data.screen_y);
	data.win = mlx_new_window(data.mlx, data.screen_x, data.screen_y, "Raycaster");
	data.img = mlx_new_image(data.mlx, data.screen_x, data.screen_y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	data.pos_x = 22;
	data.pos_y = 12;
	data.dir_x = -1;
	data.dir_y = 0;
	data.plane_x = 0;
	data.plane_y = 0.66;

	mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
