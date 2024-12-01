/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:26 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/01 17:59:19 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"
# ifndef BONUS
#  define BONUS 0
# endif

# define TILES_SIZE 64

# include <stdbool.h>

// utils
void	dump_info(t_info *info);
int		render_frame(t_info *data);
void	my_mlx_pixel_put(t_info *data, int x, int y, int color);
double	deg2rad(int deg);
void	rotate_plane(t_dpoint *plane, double angle);

// key pressed func
void	look_left(t_info *data);
void	look_right(t_info *data);
void	move_straight(t_info *data);
void	move_backward(t_info *data);
void	move_left(t_info *data);
void	move_right(t_info *data);

int		get_cl(int side, t_ipoint step);
t_tile	*c3_get_cell(t_tile *map, t_ipoint dimensions, t_ipoint pos);

/// @brief Createsa a blank map for rapahael to test the raycasting
/// @note Dev only function.
void	blank(t_info *info);

int		init_mlx_env(t_info *info);

void	cleanup_info(t_info *info);

int		c3_options(t_info *info, int argc, char *argv[]);
void	c3_perror(t_info *info);
void	print_error(const char *msg, int errno_state);

void	parse_map(t_info *info);
void	parse_args(char *arg, t_info *inf);

int		main(int argc, char *argv[]);
int		shelves_launch(t_info *info);

#endif /* CUB3D_H */
