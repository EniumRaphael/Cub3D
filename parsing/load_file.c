/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:51:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 17:51:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "cub3d_struct.h"

void	*load_file(void *data)
{
	t_info	*info;
	char	*file;

	file = NULL;
	info = (t_info *)data;
	file = ft_fd_to_buff(info->map.fd);
	if (file == NULL)
		return (info->errno_state = errno, info->last_error = ERROR_READ_FILE,
			NULL);
	info->map.fraw = ft_split(file, '\n');
	if (info->map.fraw == NULL)
		return (info->errno_state = errno, info->last_error = ERROR_MALLOC,
			NULL);
	ft_free((void **)&file);
	info->last_error = NO_ERROR;
	return (info);
}
