/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:09:00 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/16 15:17:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "ft_string.h"

#include "cub3d.h"
#include "message_error.h"

#include <unistd.h>

const char	**get_error_message(void)
{
	static const char	*error_messages[] = {
		[NO_ERROR] = "no error",
		[ERROR_UNKNOWN] = "unknown error",
		[ERROR_OPEN_FILE] = "could not open file",
		[ERROR_READ_FILE] = "could not read file",
		[ERROR_EXTENSION_FILE] = "bad file extension",
		[ERROR_NAME_FILE] = "invalid file name",
		[ERROR_MISSING_FILE] = "missing file",
		[ERROR_MALLOC] = "malloc error",
		[ERROR_PARSE] = "parse error",
		[ERROR_MAP_OPEN] = "map open error",
		[ERROR_PARSE_BG_COLOR_FORMAT] = "bad format for background color",
		[ERROR_PARSE_ALREADY_SET] = "variable was set multiple times",
		[ERROR_CLI] = "cli error",
		[ERROR_MLX] = "mlx error",
		[ERROR_TEXTURE_FORMAT] = "texture format error",
		[ERROR_IMPLEM] = "not implemented",
	};

	return (error_messages);
}

void	c3_perror(t_info *info)
{
	const char **errs_msg = get_error_message();

	if (info->last_error == NO_ERROR)
		return ;
	print_error(errs_msg[info->last_error], info->errno_state);
}

void	print_error(const char *msg, int state)
{
	ft_putstr_fd(BOLD_RED, STDERR_FILENO);
	ft_putstr_fd("Error:\n", STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	if (state != 0)
	{
		ft_putstr_fd(YELLOW, STDERR_FILENO);
		ft_putstr_fd(" due to:\n", STDERR_FILENO);
		ft_putstr_fd(BOLD_YELLOW, STDERR_FILENO);
		ft_putstr_fd(ft_strerror(state), STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
	}
	ft_putstr_fd(".\n", STDERR_FILENO);
}
