/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:05:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/20 17:09:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_vector.h"
#include "ft_string.h"
#include "ft_addons.h"

#define EPMP ERROR_PARSE_MULTIPLE_PLAYER

static bool	multiple_player_same_line(const char *str)
{
	const char	*identifiers = "NEWS";
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		if (ft_strchr(str, identifiers[i]) != ft_strrchr(str, identifiers[i]))
			return (true);
		j = i + 1;
		while (j < 4)
			if (ft_strchr(str, identifiers[j++]) && \
			ft_strchr(str, identifiers[i]))
				return (true);
		i++;
	}
	return (false);
}

int	set_player(t_info *info, int i, t_vector *str_map)
{
	t_dpoint	pos;
	char		*str;

	ft_bzero(&pos, sizeof(t_dpoint));
	if (info->player.pos.x != 0 || info->player.pos.y != 0 || i == 0 || \
	multiple_player_same_line(ft_vec_at(str_map, i)))
		return (ft_vec_destroy(&str_map), sv_errno(info, EPMP), EXIT_FAILURE);
	str = ft_strchrs(ft_vec_at(str_map, i), "SNWE");
	pos.y = i + .5;
	pos.x = str - (char *)ft_vec_at(str_map, i) + .5;
	info->player.dir = (t_dpoint){.x = 0, 0};
	info->player.pos = pos;
	info->player.pos_i = (t_ipoint){.x = (int)pos.x, .y = (int)pos.y};
	if (*str == 'N')
		info->player.dir.y = -1;
	else if (*str == 'S')
		info->player.dir.y = 1;
	else if (*str == 'W')
		info->player.dir.x = -1;
	else if (*str == 'E')
		info->player.dir.x = 1;
	info->player.plane = (t_dpoint){.x = info->player.dir.y, \
	.y = -info->player.dir.x};
	return (EXIT_SUCCESS);
}
