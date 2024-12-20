/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:53:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/20 16:54:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include <stdbool.h>
# include "mlx_structs.h"

# define FILE_EXTENSION ".cub"
# define FILE_EXTENSION_LEN 4
# define BG_SKY 0
# define BG_FLR 1
# define TILE_SIZE 64
# define WIN_COEF .5
# define WIN_TITLE "Cub3D"

// defines that should be mooved to a config option / file
# define FOV 70
# define ROT_SPEED 0.004
# define MOVE_SPEED 0.008

// -- graphic utils

typedef struct s_color
{
	union
	{
		unsigned int	color;
		struct
		{
			unsigned char	b;
			unsigned char	g;
			unsigned char	r;
			unsigned char	a;
		};
	};
}			t_color;

typedef struct s_texture
{
	t_img	*img;
	int		width;
	int		height;
	char	*path;
}			t_texture;

typedef struct s_point
{
	int	x;
	int	y;
}			t_ipoint;

typedef struct s_dpoint
{
	double	x;
	double	y;
}			t_dpoint;

// -- map utils

typedef enum e_tile
{
	EMPTY = 0,
	WALL = 1,
	WALL_ERR = 3,
	NONE = 2
}			t_tile_type;

/*
 * @param tile_visited parsing
 * @param other disponible
 * @param tile_type 16 tiles types possible
 */
typedef struct s_tile
{
	bool			tile_visited;
	unsigned int	other;
	unsigned int	tile_type;
}					t_tile;

typedef struct s_map
{
	int			fd;
	char		*path;
	t_ipoint	size;
	t_tile		*map;
	char		**fraw;
	t_texture	texture[4];
	t_color		bg_colors[2];
}				t_map;

// -- player utils

typedef struct s_player
{
	t_dpoint	pos;
	t_ipoint	pos_i;
	t_dpoint	dir;
	t_dpoint	plane;
}			t_player;

// -- cli utils

typedef struct s_cli
{
	int			debug;
	char		*file;
	bool		save;
	bool		help;
	bool		no_graphics;
}			t_cli;

// -- error utils

// keep ERROR_IMPLEM as last (used to get enum size)
typedef enum e_error
{
	NO_ERROR = 0,
	ERROR_UNKNOWN,
	ERROR_OPEN_FILE,
	ERROR_READ_FILE,
	ERROR_EXTENSION_FILE,
	ERROR_NAME_FILE,
	ERROR_MISSING_FILE,
	ERROR_MALLOC,
	ERROR_PARSE,
	ERROR_MAP_OPEN,
	ERROR_PARSE_BG_COLOR_FORMAT,
	ERROR_PARSE_NO_BG_COLOR,
	ERROR_PARSE_ALREADY_SET,
	ERROR_PARSE_META_IN_MAP,
	ERROR_PARSE_MULTIPLE_PLAYER,
	ERROR_CLI,
	ERROR_MLX,
	ERROR_TEXTURE_FORMAT,
	ERROR_TEXTURE_MISSING,
	ERROR_IMPLEM,
}			t_error;

typedef struct s_kb
{
	bool	forward;
	bool	backward;
	bool	left;
	bool	right;
	bool	l_left;
	bool	l_right;
}			t_keyboard;

typedef struct s_pixel_buffer
{
	char		*img_addr;
	t_img		*screen_buff;
	int			bpp;
	int			line_len;
	int			endian;
}				t_pixel_buffer;

// -- main struct

typedef struct s_info
{
	t_error			last_error;
	int				errno_state;
	t_keyboard		kb;

	t_xvar			*mlx_ptr;
	t_win_list		*win_ptr;
	t_ipoint		screen_size;
	t_pixel_buffer	camera;
	bool			redraw;

	t_map			map;
	t_player		player;
	t_cli			cli_ctx;

}					t_info;

#endif /* CUB3D_STRUCT_H */
