/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/17 17:23:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"

t_texture	*get_texture(int side, t_ipoint step, t_info *data)
{
	if (side == 0 && step.x > 0)
		return (&data->map.texture[0]);
	else if (side == 0 && step.x < 0)
		return (&data->map.texture[1]);
	else if (side == 1 && step.y > 0)
		return (&data->map.texture[2]);
	else
		return (&data->map.texture[3]);
}
