/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/16 14:47:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "cub3d.h"

#include "ft_math.h"
#include <math.h>

#define PT_LINEH 0
#define PT_D_START 1
#define PT_D_END 2
#define PT_X 3

#define TI_SIDE 0
#define TI_X 1

#define TD_PERP_WALL_DIST 0
#define TD_WALL_X 1

static void	draw__(t_texture *texture, int *passthroug, t_info *data, \
	double wallX)
{
	t_ipoint		text_off;
	const double	_step = (double)texture->height / passthroug[PT_LINEH];
	double			text_offset;
	char			*ptr_pix;

	text_offset = (passthroug[PT_D_START] - (double)data->screen_size.y / 2 + \
	(double)passthroug[PT_LINEH] / 2) * _step;
	text_off.x = (wallX * texture->width);
	while (passthroug[PT_D_START] < passthroug[PT_D_END])
	{
		text_off.y = (int)text_offset & (texture->height - 1);
		text_offset += _step;
		ptr_pix = texture->img->data + (text_off.y * \
		texture->img->image->bytes_per_line + text_off.x * \
		(texture->img->image->bits_per_pixel / 8));
		my_mlx_pixel_put(data, passthroug[PT_X], passthroug[PT_D_START], \
		*(unsigned int *)ptr_pix);
		passthroug[PT_D_START]++;
	}
}

//	int texX = (int)(wallX * (double)texture->width);
void	draw_(int *ti, double *td, t_ipoint step, t_info *data)
{
	const int	line_height = (int)(data->screen_size.y / \
		td[TD_PERP_WALL_DIST]) * cos(deg2rad(FOV / 2));
	int			draw_start;
	int			draw_end;
	t_texture	*texture;

	draw_start = ft_clamp(-line_height / 2 + data->screen_size.y / 2, 0, \
		data->screen_size.y - 1);
	draw_end = ft_clamp(line_height / 2 + data->screen_size.y / 2, 0, \
		data->screen_size.y - 1);
	texture = get_texture(ti[TI_SIDE], step, data);
	draw__(texture, (int []){line_height, draw_start, draw_end, ti[TI_X]}, \
	data, td[TD_WALL_X]);
}
