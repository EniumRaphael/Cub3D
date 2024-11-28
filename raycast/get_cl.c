/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:15:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/28 14:57:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"

int get_cl(int side, t_ipoint step)
{
	int color;

	if (side == 0 && step.x > 0)
		color = 0x00FF0000;
	else if (side == 0 && step.x < 0)
		color = 0x0000FF00;
	else if (side == 1 && step.y > 0)
		color = 0x000000FF;
	else
		color = 0x00FFFF00;
	return (color);
}

