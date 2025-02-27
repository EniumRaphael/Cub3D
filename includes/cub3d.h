/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:26 by rparodi           #+#    #+#             */
/*   Updated: 2024/12/17 17:18:05 by bgoulard         ###   ########.fr       */
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

// raycasting
void		draw_bg(t_info *data);
void		set_step(t_ipoint *step, t_dpoint raydir);
void		set_side_dist(t_dpoint *side_dist, t_dpoint *tb, t_ipoint pos_i);
t_texture	*get_texture(int side, t_ipoint step, t_info *data);
void		draw_(int *ti, double *td, t_ipoint step, t_info *data);

// utils
void		sv_errno(t_info *inf, int err_code);
void		draw_floor(t_info *data);
int			render_frame(t_info *data);
void		my_mlx_pixel_put(t_info *data, int x, int y, int color);
double		deg2rad(int deg);
void		rotate_plane(t_dpoint *plane, double angle);

// key pressed func
void		look_left(t_info *data);
void		look_right(t_info *data);
void		move_straight(t_info *data);
void		move_backward(t_info *data);
void		move_left(t_info *data);
void		move_right(t_info *data);

int			keyrelease_feature(int keycode, t_info *data);
int			keypress_feature(int keycode, t_info *data);
int			displacement_hook(t_info *data);
int			get_cl(int side, t_ipoint step);
t_tile		*c3_get_cell(t_tile *map, t_ipoint dimensions, t_ipoint pos);

/// @brief Createsa a blank map for rapahael to test the raycasting
/// @note Dev only function.
void		blank(t_info *info);
int			init_mlx_env(t_info *info);
void		cleanup_info(t_info *info);

int			c3_options(t_info *info, int argc, char *argv[]);
void		c3_perror(t_info *info);
void		print_error(const char *msg, int errno_state);

void		parse_map(t_info *info);
void		parse_args(char *arg, t_info *inf);

int			main(int argc, char *argv[]);
int			shelves_launch(t_info *info);

#endif /* CUB3D_H */
