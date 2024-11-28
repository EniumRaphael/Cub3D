/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:07:20 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/28 11:56:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

// define keys
# define XK_LATIN_1
# include <X11/keysym.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define MOVE_SPEED 0.5
# define ROT_SPEED 0.1

# define FOV 70 

typedef struct s_2dpoint
{
	double	x;
	double	y;
}			t_2dpoint;

typedef struct s_2ipoint
{
	int	x;
	int	y;
}			t_2ipoint;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_2ipoint	screen_size;

	t_2dpoint	pos;
	t_2ipoint	pos_i;
	t_2dpoint	dir;
	t_2dpoint	plane;
}			t_data;

#endif
