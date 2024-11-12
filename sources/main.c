/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:03 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/12 09:50:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "ft_string.h"
#include "mlx_functions.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// not normed but we'll take care of this as a niceties at the last 
// possible moment :)
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
	for (size_t i = 0; info->map.fraw[i]; i++)
		printf("\t\tmap.fraw[%zu]: %s\n", i, info->map.fraw[i]);
}

void	check_err(t_info *info)
{
	if (info->cli_ctx.file == NULL)
		return (info->last_error = ERROR_MISSING_FILE, (void)0);
	else if (ft_strlen(info->cli_ctx.file) < 5)
		return (info->last_error = ERROR_NAME_FILE, (void)0);
	else if (ft_strend_with(info->cli_ctx.file, FILE_EXTENSION) == false)
		return (info->last_error = ERROR_EXTENSION_FILE, (void)0);
	info->map.fd = open(info->cli_ctx.file, O_RDONLY);
	if (info->map.fd == -1)
		return (info->last_error = ERROR_OPEN_FILE, (void)0);
}

void	run_cub3d(t_info *info)
{
	parse_map(info);
	if (info->cli_ctx.debug)
		dump_info(info);
	if (info->last_error != NO_ERROR)
		return ;
	// todo: here
	//  - parse map
	//	- validity check
	init_mlx_env(info);
	mlx_loop(info->mlx_ptr);
//	- game loop : already loops over the mlx_ptr 
//	 -> get events if key pressed move player + run math to re-draw screen
//	- mlx cleanup : already called in parent function deprecated to call here
//	 -> previous 'segfault' were due to someone calling cleaup instead of 
//	 mlx_loop_end
}

/// @brief main function of the cub3d executable
/// @param file_arg the file path to the .cub file
/// @param info the info structure
/// @return false (0) if no error, true (1) if an error
int main_cub3d(char *file_arg, t_info *info)
{
	if (info->cli_ctx.help)
		return (cleanup_info(info), EXIT_SUCCESS);
	if (file_arg && info->cli_ctx.file == NULL)
		info->cli_ctx.file = ft_strdup(file_arg);
	check_err(info);
	if (info->last_error != NO_ERROR)
		return (c3_perror(info), cleanup_info(info), EXIT_FAILURE);
	run_cub3d(info);
	return (cleanup_info(info), info->last_error != NO_ERROR);
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
