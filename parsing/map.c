/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:31:06 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 17:51:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// proj
#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parsing.h"
// mlx
// libft - types
#include "ft_optional_types.h"
// libft
#include "ft_optional.h"

// sys std
#include <math.h>

void	parse_map(t_info *info)
{
	t_optional			opt;
	const t_data_tr_i	function_list[] = {
		load_file,
		load_textures,
		load_bgs,
		load_tiles,
		traverse_map,
		NULL,
	};

	opt = (t_optional){.val = info, .pres = OPT_SOME};
	info->map.path = info->cli_ctx.file;
	if (ft_optional_chain(&opt, function_list) == false)
		return (c3_perror(info), (void)0);
	info->player.plane = (t_dpoint){.x = 0, .y = 2 * atan(deg2rad(FOV / 2))};
	info->player.dir = (t_dpoint){.x = -1, .y = 0};
}
