/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:03 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/11 21:34:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "mlx_functions.h"
#include "mlx_structs.h"
#include "ft_string.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	dump_info(t_info *info)
{
	const char *bool_str[2] = { "True", "False"};

	printf("t_info:\n");
	printf("\tcli_ctx:\n");
	printf("\t\tfile: %s\n", info->cli_ctx.file);
	printf("\t\tdebug: %s\n", bool_str[info->cli_ctx.debug]);
	printf("\t\tsave: %s\n", bool_str[info->cli_ctx.save]);
	printf("\t\thelp: %s\n", bool_str[info->cli_ctx.help]);
	printf("\tmap:\n");
	printf("\t\tpath:%s\n", info->map.path);
	printf("\t\tfd:%d\n", info->map.fd);
	printf("\t\tsize:\t(x:%d, y:%d)\n", info->map.size.x, info->map.size.y);
	printf("\t\tplayer_pos:\t(x:%lf, y:%lf)\n", info->map.player_pos.x, info->map.player_pos.y);
}

void	check_err(t_info *info)
{
	if (info->cli_ctx.file == NULL)
		return (info->last_error = MISSING_FILE_ERROR, (void)0);
	else if (ft_strlen(info->cli_ctx.file) < 5)
		return (info->last_error = NAME_FILE_ERROR, (void)0);
	else if (ft_strend_with(info->cli_ctx.file, FILE_EXTENSION) == false)
		return (info->last_error = EXTENSION_FILE_ERROR, (void)0);
	info->map.fd = open(info->cli_ctx.file, O_RDONLY);
	if (info->map.fd == -1)
		return (info->last_error = OPEN_FILE_ERROR, (void)0);
}

void	run_cub3d(t_info *info)
{
	// code here
	//  - parse map
	//	- validity check
	//  - mlx inits
	//		- game loop
	init_mlx_env(info);
	//	- mlx cleanup
}

int main_cub3d(char *file_arg, t_info *info)
{
	if (info->cli_ctx.help)
		return (cleanup_info(info), EXIT_SUCCESS);
	if (file_arg && info->cli_ctx.file == NULL)
		info->cli_ctx.file = ft_strdup(file_arg);
	check_err(info);
	if (info->last_error != NO_ERROR)
		return (c3_perror(info), cleanup_info(info), EXIT_FAILURE);
	if (info->cli_ctx.debug)
		(dump_info(info), printf("file_arg: %s\n", file_arg));
	run_cub3d(info);
	return (cleanup_info(info), EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		parsed_args;

	parsed_args = c3_options(&info, argc, argv);
	if (parsed_args == -1)
		return (EXIT_FAILURE);
	return (main_cub3d(argv[parsed_args], &info));
}
