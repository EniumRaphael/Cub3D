/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:41:07 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/11 17:43:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

#include <stdbool.h>
# define C3D_PRS_PLS "SO"
# define C3D_PRS_PLW "WE"
# define C3D_PRS_PLN "NO"
# define C3D_PRS_PLE "EA"

# define C3D_PRS_WLL_TRAIL ' '
# define C3D_PRS_WLL '1'
# define C3D_PRS_EMP '0'

enum e_tile_m {
	EMPTY,
	DOOR_OPEN,
	DOOR_ANIM,
	DOOR_CLOSE,
	WALL_TRAIL,
	WALL,
	PLAYER_N,
	PLAYER_S,
	PLAYER_E,
	PLAYER_W
};

typedef struct s_map_truth {
	enum e_tile_m	tile;
	char			chr[2];
} t_map_truth;

typedef struct s_tile {
	enum e_tile_m	tile;
	bool			visited;
} t_tile;

extern const t_map_truth g_map_table[];
/*
= {
{EMPTY, C3D_PRS_EMP},
{WALL_TRAIL, C3D_PRS_WLL_TRAIL},
{WALL, C3D_PRS_WLL},
{PLAYER_N, C3D_PRS_PLN},
{PLAYER_S, C3D_PRS_PLS},
{PLAYER_E, C3D_PRS_PLE},
{PLAYER_W, C3D_PRS_PLW},
};
*/

enum e_identifiers {
	UNKNOWN = 0,
	TEXTURE_N,
	TEXTURE_S,
	TEXTURE_E,
	TEXTURE_W,
	FLOOR,
	CEILING,
};

typedef struct s_identifiers {
	enum e_identifiers	id;
	char				*path;
} t_identifiers;

#endif /* CUB3D_PARSING_H */
