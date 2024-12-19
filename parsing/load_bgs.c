/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:47:37 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/19 22:10:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parsing.h"
#include "ft_string.h"
#include <stdbool.h>
#include <stdio.h>

// col [ 3 ] is alpha channel (not used in the project)
bool	color_from_str(const char *str, t_color *color)
{
	int			col[4];
	const char	*arr[3];

	if (ft_strcnb(str, ',') != 2)
		return (false);
	arr[0] = ft_strtok((char *)str, ",");
	arr[1] = ft_strtok(NULL, ",");
	arr[2] = ft_strtok(NULL, ",");
	if (!arr[0] || !arr[1] || !arr[2] || !ft_str_isnum(arr[0]) || \
	!ft_str_isnum(arr[1]) || !ft_str_isnum(arr[2]))
		return (false);
	col[0] = ft_atoi(arr[0]);
	col[1] = ft_atoi(arr[1]);
	col[2] = ft_atoi(arr[2]);
	col[3] = 255;
	if (ft_inrange(col[0], 0, 255) == false || \
	ft_inrange(col[1], 0, 255) == false || \
	ft_inrange(col[2], 0, 255) == false)
		return (false);
	*color = (t_color){.r = col[0], .g = col[1], .b = col[2], .a = col[3]};
	return (true);
}

bool	load_bg(t_info *info, const char *line, const char **id_str, bool *tpl)
{
	t_color	color;
	size_t	id_idx;

	id_idx = 0;
	ft_bzero(&color, sizeof(t_color));
	while (id_str[id_idx] && ft_strstart_with(line, id_str[id_idx]) == false)
		id_idx++;
	if (color_from_str(line + ft_strlen(id_str[id_idx]), &color) == false)
		return (info->last_error = ERROR_PARSE_BG_COLOR_FORMAT, false);
	if (id_idx == BG_FLR && info->map.bg_colors[BG_FLR].color == 0)
		info->map.bg_colors[BG_FLR] = color;
	else if (id_idx == BG_SKY && info->map.bg_colors[BG_SKY].color == 0)
		info->map.bg_colors[BG_SKY] = color;
	else
		return (info->last_error = ERROR_PARSE_ALREADY_SET, false);
	tpl[id_idx] = true;
	return (true);
}

void	*load_bgs(void *data)
{
	const char	*id_str[] = {[BG_FLR] = "F ", [BG_SKY] = "C ", [2] = NULL};
	t_info		*info;
	size_t		i;
	bool		tuple[2];

	i = 0;
	info = (t_info *)data;
	ft_bzero(tuple, sizeof(bool) * 2);
	while (info->map.fraw[i])
	{
		if (is_identifier(info->map.fraw[i], id_str) && \
		load_bg(info, info->map.fraw[i], id_str, tuple) == false)
			return (NULL);
		i++;
	}
	if (tuple[BG_FLR] == false || tuple[BG_SKY] == false)
		return (sv_errno(info, ERROR_PARSE_NO_BG_COLOR), NULL);
	return (info);
}
