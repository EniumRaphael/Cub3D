/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:03 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/01 18:53:12 by rparodi          ###   ########.fr       */
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

void	dump_map(t_tile *map, t_ipoint size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		printf("\t\t\t");
		while (j < size.x)
		{
			printf("%d", map[i * size.x + j].tile_type);
			j++;
		}
		printf("\n");
		i++;
	}
}

// not normed but we'll take care of this as a niceties at the last
// possible moment :)
void	dump_info(t_info *info)
{
	const char	*bool_str[2] = {"False", "True"};
	size_t		i;

	i = 0;
	printf("t_info:\n");
	printf("\tplayer:\n");
	printf("\t\tpos_i:\t(x: %d, y:%d)\n", \
		info->player.pos_i.x, info->player.pos_i.y);
	printf("\t\tpos:\t(x:%lf, y:%lf)\n", \
		info->player.pos.x, info->player.pos.y);
	printf("\t\tdir:\t(x:%lf, y:%lf)\n", \
		info->player.dir.x, info->player.dir.y);
	printf("\t\tplane:\t(x:%lf, y:%lf)\n", \
		info->player.plane.x, info->player.plane.y);
	printf("\tcli_ctx:\n");
	printf("\t\tfile:\t%s\n", info->cli_ctx.file);
	printf("\t\tdebug:\t%s\n", bool_str[info->cli_ctx.debug]);
	printf("\t\tsave:\t%s\n", bool_str[info->cli_ctx.save]);
	printf("\t\thelp:\t%s\n", bool_str[info->cli_ctx.help]);
	printf("\tmap:\n");
	printf("\t\tpath:%s\n", info->map.path);
	printf("\t\tfd:\t%d\n", info->map.fd);
	printf("\t\tsize:\t(x:%d, y:%d)\n", info->map.size.x, info->map.size.y);
	while (info->map.fraw[i])
	{
		printf("\t\tmap.fraw[%*zu]: %s\n", 3, i, info->map.fraw[i]);
		i++;
	}
	printf("\t\ttexture[0]: %p\n", info->map.texture[0]);
	printf("\t\ttexture[1]: %p\n", info->map.texture[1]);
	printf("\t\ttexture[2]: %p\n", info->map.texture[2]);
	printf("\t\ttexture[3]: %p\n", info->map.texture[3]);
	printf("\t\tmap: %p\n", info->map.map);
	dump_map(info->map.map, info->map.size);
	printf("\tlast_error: %d\n", info->last_error);
	printf("\terno_state: %d\n", info->errno_state);
	printf("\n");
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
		return (info->errno_state = errno, info->last_error = ERROR_OPEN_FILE,
			(void)0);
}

void	run_cub3d(t_info *info)
{
	if (init_mlx_env(info) != NO_ERROR)
		return ;
	parse_map(info);
	if (info->cli_ctx.debug)
		dump_info(info);
	if (info->last_error != NO_ERROR)
		return ;
	info->camera.screen_buff = mlx_new_image(info->mlx_ptr, info->screen_size.x,
			info->screen_size.y);
	info->camera.img_addr = mlx_get_data_addr(info->camera.screen_buff,
			&info->camera.bpp, &info->camera.line_len, &info->camera.endian);
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
