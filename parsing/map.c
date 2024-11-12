/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:31:06 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/12 11:29:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "ft_string.h"
#include "ft_optional.h"
#include "ft_optional_types.h"
#include <stdio.h>
#include <sys/types.h>

// steps:
// 1. load_map into a buffer
// 2. store the map while deleting trailing newlines
void *load_map(void *data)
{
	t_info	*info = (t_info *)data;
	char	*file = NULL;

	file = ft_fd_to_buff(info->map.fd);
	info->map.fraw = ft_split(file, '\n');

	ft_free((void **)&file);
	return (info->last_error = ERROR_IMPLEM, NULL);
}

void *traverse_map(void *data)
{
	t_info *info = (t_info *)data;

	info->last_error = ERROR_IMPLEM;
	return (NULL);
}

void parse_map(t_info *info)
{
	t_optional opt = {OPT_NONE, NULL};
	const t_data_tr_i function_list[] = {
		load_map,
		traverse_map,
		NULL,
	};

	opt.val = info;
	opt.pres = OPT_SOME;
	info->map.path = info->cli_ctx.file;
	if (ft_optional_chain(&opt, function_list) == false)
		return (c3_perror(info), (void)0);
}
