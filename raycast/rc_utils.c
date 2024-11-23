/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:24:35 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/23 12:33:39 by rparodi          ###   ########.fr       */
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
  double	distance;
  t_dpoint	direction;
  t_dpoint	rayon;

  distance = 0;
  direction.x = cos(angle);
  direction.y = sin(angle);
  rayon.x = 0;
  rayon.y = 0;
     while (distance < MAX_RANGE)
    {
        rayon.x = direction.x * distance;
        rayon.y = direction.y * distance;
        if (info->map.map[(int)info->map.fraw[(int)rayon.x][(int)rayon.y]] == '1')
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
     while (x < width)
     {
         angle = info->player.view + atan(\
    (spacing / 2 - x * spacing / (width - 1)) / focal);
         rc_launch(info, angle);
         x++;
     }
 }

t_win_list	*c3_init_mlx_window(t_info *info)
{
	void	*window;
	int		i;
	int		j;
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_get_screen_size(info->mlx_ptr, &x, &y);

	i = 0;
	window = mlx_new_window(info->mlx_ptr, x, y, "Raycasting");
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (info->map.fraw[i / info->map.size.x][j / info->map.size.y] == '1')
				mlx_pixel_put(info->mlx_ptr, window, i, j, 0xFFFFFF);
			else
				mlx_pixel_put(info->mlx_ptr, window, i, j, 0x000000);
			j++;
		}
	 i++;
	}
	mlx_loop(info->mlx_ptr);
	return (window);
 }
