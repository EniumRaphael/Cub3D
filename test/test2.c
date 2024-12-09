/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:09:00 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/05 19:07:51 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minilibx-linux/mlx.h"
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

void	clear_window(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void draw_floor(t_data *data)
{
	int		 y;
	int		 x;

	y = WINDOW_HEIGHT / 2;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int	render_frame(t_data *data)
{
	clear_window(data);
	draw_floor(data);
	for(int x = 0; x < WINDOW_WIDTH; x++)
	{
		double cameraX = 2 * x / (double)WINDOW_WIDTH - 1;
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

		int lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);
		int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
		if(drawEnd >= WINDOW_HEIGHT) drawEnd = WINDOW_HEIGHT - 1;

		// Get correct wall texture based on direction
		t_texture *wall_tex;
		if (side == 0)
		{
			if (stepX > 0)
				wall_tex = &data->wall_so;
			else
				wall_tex = &data->wall_no;
		}
		else
		{
			if (stepY > 0)
				wall_tex = &data->wall_ea;
			else
				wall_tex = &data->wall_we;
		}

		// Wall texture calculations
		double wallX;
		if (side == 0) wallX = data->pos_y + perpWallDist * rayDirY;
		else wallX = data->pos_x + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)wall_tex->width);

		double step = 1.0 * wall_tex->height / lineHeight;
		double texPos = (drawStart - WINDOW_HEIGHT / 2 + lineHeight / 2) * step;

		for(int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (wall_tex->height - 1);
			texPos += step;

			char *tex_pixel = wall_tex->addr + (texY * wall_tex->line_length + texX * (wall_tex->bits_per_pixel / 8));
			my_mlx_pixel_put(data, x, y, *(unsigned int*)tex_pixel);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int main(void)
{
	t_data data;
	int width, height;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Raycaster");
	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	// Load wall textures
	data.wall_no.img = mlx_xpm_file_to_image(data.mlx, "./textures/b.xpm", &width, &height);
	data.wall_no.addr = mlx_get_data_addr(data.wall_no.img, &data.wall_no.bits_per_pixel,
					&data.wall_no.line_length, &data.wall_no.endian);
	data.wall_no.width = width;
	data.wall_no.height = height;

	data.wall_so.img = mlx_xpm_file_to_image(data.mlx, "./textures/cobblestone_32.xpm", &width, &height);
	data.wall_so.addr = mlx_get_data_addr(data.wall_so.img, &data.wall_so.bits_per_pixel,
					&data.wall_so.line_length, &data.wall_so.endian);
	data.wall_so.width = width;
	data.wall_so.height = height;

	data.wall_we.img = mlx_xpm_file_to_image(data.mlx, "./textures/sandy_32.xpm", &width, &height);
	data.wall_we.addr = mlx_get_data_addr(data.wall_we.img, &data.wall_we.bits_per_pixel,
					&data.wall_we.line_length, &data.wall_we.endian);
	data.wall_we.width = width;
	data.wall_we.height = height;

	data.wall_ea.img = mlx_xpm_file_to_image(data.mlx, "./textures/wasteland_32.xpm", &width, &height);
	data.wall_ea.addr = mlx_get_data_addr(data.wall_ea.img, &data.wall_ea.bits_per_pixel,
					&data.wall_ea.line_length, &data.wall_ea.endian);
	data.wall_ea.width = width;
	data.wall_ea.height = height;

	// Load floor texture
	data.floor.img = mlx_xpm_file_to_image(data.mlx, "./textures/b.xpm", &width, &height);
	data.floor.addr = mlx_get_data_addr(data.floor.img, &data.floor.bits_per_pixel,
					&data.floor.line_length, &data.floor.endian);
	data.floor.width = width;
	data.floor.height = height;

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
