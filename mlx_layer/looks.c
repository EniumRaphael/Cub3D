/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:11:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/28 14:51:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"

void	look_left(t_info *data)
{
	rotate_plane(&data->player.dir, ROT_SPEED);
	rotate_plane(&data->player.plane, ROT_SPEED);
}

void	look_right(t_info *data)
{
	rotate_plane(&data->player.dir, -ROT_SPEED);
	rotate_plane(&data->player.plane, -ROT_SPEED);
}
