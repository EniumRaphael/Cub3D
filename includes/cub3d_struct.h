/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:53:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/28 15:36:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include <stdbool.h>
# include "mlx_structs.h"

# define FILE_EXTENSION ".cub"
# define FILE_EXTENSION_LEN 4
# define BG_CLG 0
# define BG_FLR 1
#define TILE_SIZE 64

// defines that should be mooved to a config option / file
#define FOV 70
#define ROT_SPEED 0.1
#define MOVE_SPEED 0.5

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
}			t_tile_type;

typedef union u_tile
{
	int		raw_tile;
	struct {
		unsigned int	tile_visited: 1; // parsing
		unsigned int    other: 27; // disponible
		unsigned int	tile_type: 4; // 16 tile types possible
	};
} t_tile;

typedef struct s_map
{
	int			fd;
	char		*path;
	t_dpoint	player_pos;
	t_ipoint	size;
	t_tile		*map;
	char		**fraw;
	t_img		*texture[4];
	t_texture	texture_[4];
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
	ERROR_CLI,
	ERROR_MLX,
	ERROR_TEXTURE_FORMAT,
	ERROR_IMPLEM,
}			t_error;

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
	t_error		last_error;
	int			errno_state;

	t_xvar			*mlx_ptr;
	t_win_list		*win_ptr;
	t_ipoint		screen_size;
	t_pixel_buffer	camera;

	t_map		map;
	t_player	player;
	t_cli		cli_ctx;

}				t_info;

#endif /* CUB3D_STRUCT_H */
