/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:41:07 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/20 17:07:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

# include "cub3d_struct.h"
# include "ft_vector_types.h"
# include <stdbool.h>

# define C3D_PRS_PLS "SO"
# define C3D_PRS_PLW "WE"
# define C3D_PRS_PLN "NO"
# define C3D_PRS_PLE "EA"

# define C3D_PRS_WLL_TRAIL ' '
# define C3D_PRS_WLL '1'
# define C3D_PRS_EMP '0'

t_tile	*c3_get_cell(t_tile *map, t_ipoint dimensions, t_ipoint pos);
bool	is_identifier(const char *str, const char **id_str);
int		set_player(t_info *info, int i, t_vector *str_map);

void	*load_file(void *data);
void	*load_bgs(void *data);
void	*load_map(void *data);
void	*load_textures(void *data);
void	*load_tiles(void *data);
void	*traverse_map(void *data);

#endif /* CUB3D_PARSING_H */
