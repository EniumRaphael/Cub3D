/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:24:35 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/28 15:15:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "mlx_functions.h"
#include "raycast.h"
#include <stdlib.h>

/**
	* @brief Launches a ray for raycasting to determine the distance to the first wall.
 *
 * This function calculates the distance of a ray cast in a specified angle
 * until it either hits a wall or reaches the maximum range.
 *

	* @param info      A pointer to the `t_info` structure containing the map and other relevant data.
 * @param angle     The angle of the ray being cast, in radians.
 *
 * @return The distance from the starting position to the first wall hit.
 *         If no wall is hit within `MAX_RANGE`,
	the function returns `MAX_RANGE`.
 */
double	rc_launch(t_info *info, double angle)
{
	double		distance = 0;
	t_dpoint	direction = { cos(angle), sin(angle) };
	t_dpoint	rayon = { 0, 0 };

	while (distance < MAX_RANGE)
	{
		rayon.x = info->player.pos.x + direction.x * distance;
		rayon.y = info->player.pos.y + direction.y * distance;
		if (info->map.fraw[(int)(rayon.y)][(int)(rayon.x)] == '1')
			return (distance);
		distance += STEP_SIZE;
	}
	return (MAX_RANGE);
}

/**
 * @brief Launches algorithm over a specified width with angle adjustments.
 *
 * @param info         The structure of the game (for the view)
 * @param spacing      The spacing between rays.
 * @param focal        The focal length affecting the angle adjustment.
 * @param width        The total width (number of columns) to iterate over.
 *

	* @note The function assumes `rc_launch` is defined elsewhere to handle the angle.
 */

void	draw_line(t_info *info, int x, int start, int end, unsigned int color)
{
	while (start <= end)
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, start, color);
		start++;
	}
}

/*
{
	info->player.pos = (t_dpoint){ 4.5, 4.5 }; // Starting in the middle of the map
	info->player.view = 0;	int		x;
	double	angle;
	double	distance;
	double	projection_plane = info->map.size.x / (2.0 * tan(M_PI / 6.0));

	for (x = 0; x < info->map.size.x; x++)
	{
		angle = info->player.view + atan((x - info->map.size.x / 2.0) / projection_plane);
		distance = rc_launch(info, angle);
		int line_height = (int)(TILE_SIZE / distance * projection_plane);
		int start = (info->map.size.y / 2) - (line_height / 2);
		int end = (info->map.size.y / 2) + (line_height / 2);

		if (start < 0) start = 0;
		if (end >= info->map.size.y) end = info->map.size.y - 1;

		draw_line(info, x, start, end, 0xFFFFFF);
	}
}*/

int shelves_launch(t_info *info)
{
	render_frame(info);
	return (EXIT_SUCCESS);
}
