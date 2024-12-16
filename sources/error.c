/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:09:00 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/16 14:37:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "cub3d.h"
#include "message_error.h"

#include <unistd.h>

static const char	*g_error_message[] = {
	"no error",
	"unknown error",
	"could not open file",
	"could not read file",
	"bad file extension",
	"invalid file name",
	"missing file",
	"malloc error",
	"parse error",
	"map open error",
	"bad format for background color",
	"variable was set multiple times",
	"cli error",
	"mlx error",
	"texture format error",
	"not implemented",
};

void	c3_perror(t_info *info)
{
	if (info->last_error == NO_ERROR)
		return ;
	print_error(g_error_message[info->last_error], info->errno_state);
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
