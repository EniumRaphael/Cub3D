/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:55:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/13 07:15:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include <stdbool.h>
# include "mlx_structs.h"

# define FILE_EXTENSION ".cub"
# define FILE_EXTENSION_LEN 4

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
	EMPTY,
	WALL
}			t_tile;

typedef struct s_map
{
	int			fd;
	char		*path;
	t_dpoint	player_pos;
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
	double		view;
}			t_player;

// -- cli utils

typedef struct s_cli
{
	int			debug;
	char		*file;
	bool		save;
	bool		help;
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
	ERROR_IMPLEM,
}			t_error;

// -- main struct

typedef struct s_info
{
	t_error		last_error;

	t_xvar		*mlx_ptr;
	t_win_list	*win_ptr;
	t_map		map;
	t_player	player;
	t_cli		cli_ctx;
}				t_info;

#endif /* CUB3D_STRUCT_H */
