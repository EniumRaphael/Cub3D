/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_impl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:12:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/15 09:08:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "ft_string.h"

void	c3_set_file(void *usr_control_struct, const char *arg)
{
	t_cli	*cli_ctx;

	cli_ctx = (t_cli *)usr_control_struct;
	cli_ctx->file = ft_strdup(arg);
}

void	c3_set_debug(void *usr_control_struct)
{
	t_cli	*cli_ctx;

	cli_ctx = (t_cli *)usr_control_struct;
	cli_ctx->debug = true;
}

void	c3_set_save(void *usr_control_struct)
{
	t_cli	*cli_ctx;

	cli_ctx = (t_cli *)usr_control_struct;
	cli_ctx->save = true;
}

void	c3_print_help(void *usr_control_struct)
{
	t_cli		*cli_ctx;
	const char	*help_str = \
	"Usage: cub3d [options] <file>\nOptions:\n"						\
	"\t-f, --file <file> : specify the file to load\n"				\
	"\t-d, --debug : enable debug mode\n"							\
	"\t-s, --save : save the state of the 'game' when closing\n"	\
	"\t-h, --help : print this help\n";

	cli_ctx = (t_cli *)usr_control_struct;
	cli_ctx->help = true;
	ft_putstr_fd(help_str, STDOUT_FILENO);
}
