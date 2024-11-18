/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:14:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/15 09:03:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"
#include "cub3d_options.h"

#include "ft_args.h"
#include "ft_args_types.h"
#include "ft_string.h"

int	c3_options(t_info *info, int argc, char *argv[])
{
	int			parsed_args;
	const t_opt	opts[] = {
	{"file", 'f', c3_set_file, OPT_ARG | OPT_EQSIGN | OPT_OTHER},
	{"debug", 'd', c3_set_debug, 0},
	{"save", 's', c3_set_save, 0},
	{"help", 'h', c3_print_help, 0},
		// add more options here put the implementation in options_impl.c
		//	 if you want custom option see ft_args_types.h for more info 
		//	 code example in it.
	{NULL, 0, NULL, 0}
	};

	(void)argc;
	ft_bzero(info, sizeof(t_info));
	ft_setup_prog((const char *const *)argv);
	ft_set_opt_list(opts);
	parsed_args = ft_parse_args((const char **)argv, &(info->cli_ctx));
	return (parsed_args);
}
