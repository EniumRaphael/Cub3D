/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:24:35 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/01 18:39:11 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "mlx_functions.h"
#include "raycast.h"
#include <stdlib.h>

/**
 * @brief Launches a ray for raycasting to determine the distance to the first 
 * wall.
 *
 * This function calculates the distance of a ray cast in a specified angle
 * until it either hits a wall or reaches the maximum range.
 *
 * @param info      A pointer to the `t_info` structure containing the map 
 * and other relevant data.
 * @param angle     The angle of the ray being cast, in radians.
 *
 * @return The distance from the starting position to the first wall hit.
 *         If no wall is hit within `MAX_RANGE`,
	the function returns `MAX_RANGE`.
 */
double	rc_launch(t_info *info, double angle)
{
	double		distance;
	t_dpoint	direction;
	t_dpoint	rayon;

	distance = 0;
	direction.x = cos(angle);
	direction.y = sin(angle);
	rayon.x = 0;
	rayon.y = 0;
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

int	shelves_launch(t_info *info)
{
	render_frame(info);
	return (EXIT_SUCCESS);
}
