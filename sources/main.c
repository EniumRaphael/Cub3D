/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:03 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/16 15:20:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "ft_string.h"
#include "mlx_functions.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	check_err(t_info *info)
{
	if (info->cli_ctx.file == NULL)
		return (info->last_error = ERROR_MISSING_FILE, (void)0);
	else if (ft_strlen(info->cli_ctx.file) < ft_strlen(FILE_EXTENSION))
		return (info->last_error = ERROR_EXTENSION_FILE, (void)0);
	else if (ft_strend_with(info->cli_ctx.file, FILE_EXTENSION) == false)
		return (info->last_error = ERROR_EXTENSION_FILE, (void)0);
	info->map.fd = open(info->cli_ctx.file, O_RDONLY);
	if (info->map.fd == -1)
		return (info->errno_state = errno, info->last_error = ERROR_OPEN_FILE,
			(void)0);
}

void	run_cub3d(t_info *info)
{
	if (init_mlx_env(info) != NO_ERROR)
		return (c3_perror(info));
	parse_map(info);
	if (info->cli_ctx.debug)
		ft_putstr_fd("no debug mod on production run", STDERR_FILENO);
	if (info->last_error != NO_ERROR)
		return (c3_perror(info));
	if (info->cli_ctx.no_graphics == true)
		return ;
	info->camera.screen_buff = mlx_new_image(info->mlx_ptr, info->screen_size.x,
			info->screen_size.y);
	info->camera.img_addr = mlx_get_data_addr(info->camera.screen_buff,
			&info->camera.bpp, &info->camera.line_len, &info->camera.endian);
	info->redraw = true;
	mlx_loop(info->mlx_ptr);
}

/// @brief main function of the cub3d executable
/// @param file_arg the file path to the .cub file
/// @param info the info structure
/// @return false (0) if no error, true (1) if an error
int	main_cub3d(char *file_arg, t_info *info)
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
