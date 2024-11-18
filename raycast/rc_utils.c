/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:24:35 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/18 15:41:34 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "mlx_functions.h"
#include "raycast.h"

/**
 * @brief convert a angle in degrees to radian
 *
 * @param degrees the angle in degrees
 * @return the angle in radian
 */
double	cub_convert_deg_to_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

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
 *         If no wall is hit within `MAX_RANGE`, the function returns `MAX_RANGE`.
 */
double	rc_launch(t_info *info, double angle)
{
	double		distance;
	t_dpoint	direction;
	t_dpoint	rayon;

	distance = 0;
	direction.x = 0;
	direction.y = 0;
	rayon.x = 0;
	rayon.y = 0;
    while (distance < MAX_RANGE)
	{
        rayon.x = direction.x * distance;
        rayon.y = direction.y * distance;
        if (info->map.map[info->map.fraw[(int)rayon.x][(int)rayon.y]] == WALL)
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
void	shelves_launch(t_info *info, double spacing, double focal, int width)
{
    int x;
    double angle;
    
    x = 0;
    angle = 0;
    while (x < width)
    { 
        angle = info->player.view + atan(\
			(spacing / 2 - x * spacing / (width - 1)) / focal);
        rc_launch(info, angle);
        x++;
    }
}
