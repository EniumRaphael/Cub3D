/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:24:35 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/12 12:38:14 by rparodi          ###   ########.fr       */
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

void	rc_launch(double angle)
{
	return ;
}

/**
 * @brief Launches algorithm over a specified width with angle adjustments.
 *
 * @param delta        The initial angle offset for the ray.
 * @param spacing      The spacing between rays.
 * @param focal        The focal length affecting the angle adjustment.
 * @param width        The total width (number of columns) to iterate over.
 *
 * @note The function assumes `rc_launch` is defined elsewhere to handle the angle.
 */
void	shelves_launch(double delta, double spacing, double focal, int width)
{
    int x;
    double angle;
    
    x = 0;
    angle = 0;
    while (x < width)
    { 
        angle = delta + atan((spacing / 2 - x * spacing / (width - 1)) / focal);
        rc_launch(angle);
        x++;
    }
}
