/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:47:37 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 17:52:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "cub3d_parsing.h"
#include "ft_string.h"

bool	color_from_str(const char *str, t_color *color)
{
	int		col[4];
	char	**split;

	split = ft_split(str, ',');
	if (split == NULL)
		return (false);
	col[0] = ft_atoi(split[0]);
	col[1] = ft_atoi(split[1]);
	col[2] = ft_atoi(split[2]);
	if (split[3])
		col[3] = ft_atoi(split[3]);
	else
		col[3] = 255;
	if (col[0] < 0 || col[0] > 255 || col[1] < 0 || col[1] > 255 || col[2] < 0
		|| col[2] > 255 || col[3] < 0 || col[3] > 255)
		return (false);
	*color = (t_color){.r = col[0], .g = col[1], .b = col[2], .a = col[3]};
	ft_free_2d((void **)split);
	return (true);
}

bool	load_bg(t_info *info, const char *line, const char **id_str)
{
	t_color	color;
	size_t	i;

	i = 0;
	ft_bzero(&color, sizeof(t_color));
	while (id_str[i])
	{
		if (ft_strstart_with(line, id_str[i]) && (color_from_str(line
					+ ft_strlen(id_str[i]), &color) == false || color.a < 255))
			return (info->last_error = ERROR_PARSE, false);
		if (ft_strstart_with(id_str[i], "F "))
			info->map.bg_colors[BG_FLR] = color;
		else
			info->map.bg_colors[BG_CLG] = color;
		i++;
	}
	if (color.color == 0)
		return (info->last_error = ERROR_PARSE, false);
	return (true);
}

void	*load_bgs(void *data)
{
	const char	*id_str[] = {"F ", "C ", NULL};
	t_info		*info;
	size_t		i;

	i = 0;
	info = (t_info *)data;
	while (info->map.fraw[i])
	{
		if (is_identifier(info->map.fraw[i], id_str) && load_bg(info,
				info->map.fraw[i], id_str) == false)
			return (NULL);
		i++;
	}
	return (info);
}
