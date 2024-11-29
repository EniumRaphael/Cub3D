/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:09:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/29 15:33:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include <math.h>

void	my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	uint	*dst;

	x *= data->camera.bpp / 8;
	dst = (uint *)(data->camera.img_addr + (y * data->camera.line_len + x));
	*dst = color;
}

double	deg2rad(int deg)
{
	return (deg * M_PI / 180);
}

void	rotate_plane(t_dpoint *plane, double angle)
{
	double	old_plane_x;
//	double	old_plane_y;

	old_plane_x = (*plane).x;
//	old_plane_y = (*plane).y;
	plane->x = plane->x * cos(angle) - plane->y * sin(angle);
	plane->y = old_plane_x * sin(angle) + plane->y * cos(angle);
}
