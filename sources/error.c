/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:09:00 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/10 16:13:25 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "cub3d.h"
#include "message_error.h"

#include <unistd.h>

const char *g_error_message[] = {
	"no error",
	"unknown error",

	"could not open file",
	"could not read file",
	"bad file extension",
	"invalid file name",
	"missing file",
	"malloc error",
	"parse error",
	"cli error",
	"mlx error",
};

void	c3_perror(t_info *info)
{
	if (info->last_error == NO_ERROR)
		return ;
	print_error(g_error_message[info->last_error]);
}

void	print_error(const char *msg)
{
	ft_putstr_fd(BOLD_RED, STDERR_FILENO);
	ft_putstr_fd("Error:\n", STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
