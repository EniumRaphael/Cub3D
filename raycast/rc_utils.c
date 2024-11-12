/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:24:35 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/12 15:08:08 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "mlx_functions.h"
#include "raycast.h"

double	cub_convert_rad_to_deg(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

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
        rayon.x += direction.x * STEP_SIZE;
        rayon.y += direction.y * STEP_SIZE;
        distance += STEP_SIZE;
        if (info->map.map(info->map.fraw[(int)rayon.x][(int)rayon.y]) == WALL)
            return (distance);
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
        angle = info->player.view + atan((spacing / 2 - x * spacing / (width - 1)) / focal);
        rc_launch(info, angle);
        x++;
    }
}
