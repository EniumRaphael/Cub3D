/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:26 by rparodi           #+#    #+#             */
/*   Updated: 2024/10/31 16:54:38 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

# include "libft.h"
# include "message_error.h"

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_map
{
	int		fd;
	char	*path;
	char	*oneline;
	char	**content;
	double	spawn_x;
	double	spawn_y;
}			t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	view_x;
	double	view_y;
}			t_player;

typedef struct s_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_player	player;
}				t_info;

void	print_error(char *msg);
bool	ft_parse_args(int argc, char *argv[]);
int		main(int argc, char *argv[]);

#endif
