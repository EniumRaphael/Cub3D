/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:09:00 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/20 17:02:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "ft_string.h"

#include "cub3d.h"
#include "message_error.h"

#include <unistd.h>

const char	**get_error_message(void)
{
	static const char	*err_msg[ERROR_IMPLEM + 1] = {NULL};

	err_msg[NO_ERROR] = "no error";
	err_msg[ERROR_UNKNOWN] = "unknown error";
	err_msg[ERROR_OPEN_FILE] = "could not open file";
	err_msg[ERROR_READ_FILE] = "could not read file";
	err_msg[ERROR_EXTENSION_FILE] = "bad file extension";
	err_msg[ERROR_NAME_FILE] = "invalid file name";
	err_msg[ERROR_MISSING_FILE] = "missing file";
	err_msg[ERROR_MALLOC] = "malloc error";
	err_msg[ERROR_PARSE] = "parse error";
	err_msg[ERROR_MAP_OPEN] = "map open error";
	err_msg[ERROR_PARSE_BG_COLOR_FORMAT] = "bad format for background color";
	err_msg[ERROR_PARSE_ALREADY_SET] = "variable was set multiple times";
	err_msg[ERROR_CLI] = "cli error";
	err_msg[ERROR_MLX] = "mlx error";
	err_msg[ERROR_TEXTURE_FORMAT] = "texture format error";
	err_msg[ERROR_IMPLEM] = "not implemented";
	err_msg[ERROR_TEXTURE_MISSING] = "texture missing";
	err_msg[ERROR_PARSE_NO_BG_COLOR] = "no background color provided";
	err_msg[ERROR_PARSE_META_IN_MAP] = "meta data in map (should be above)";
	err_msg[ERROR_PARSE_MULTIPLE_PLAYER] = "multiple player in map";
	err_msg[ERROR_NO_PLAYER] = "no player in map";
	return (err_msg);
}

void	c3_perror(t_info *info)
{
	const char	**errs_msg = get_error_message();
	const char	*msg;

	if (info->last_error == NO_ERROR)
		return ;
	msg = errs_msg[info->last_error];
	if (!msg)
		msg = errs_msg[ERROR_UNKNOWN];
	print_error(msg, info->errno_state);
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
