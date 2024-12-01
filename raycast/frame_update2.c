/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:55:11 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/01 18:57:21 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"

#include "mlx_functions.h"
#include "ft_string.h"
#include "ft_math.h"

#include <math.h>
#include <unistd.h>

void	set_step(t_ipoint *step, t_dpoint raydir)
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

void	set_side_dist(t_dpoint *side_dist, t_dpoint *tb, t_ipoint pos_i)
{
	t_dpoint	ray_dir;
	t_dpoint	pos;
	t_dpoint	delta_dist;

	ray_dir = tb[0];
	pos = tb[1];
	delta_dist = tb[2];
	if (ray_dir.x < 0)
		side_dist->x = (pos.x - pos_i.x) * delta_dist.x;
	else
		side_dist->x = (pos_i.x + 1.0 - pos.x) * delta_dist.x;
	if (ray_dir.y < 0)
		side_dist->y = (pos.y - pos_i.y) * delta_dist.y;
	else
		side_dist->y = (pos_i.y + 1.0 - pos.y) * delta_dist.y;
}
