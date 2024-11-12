/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:26 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/12 08:33:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"
# ifndef BONUS
#  define BONUS 0
# endif

# include <stdbool.h>

int		init_mlx_env(t_info *info);

void	cleanup_info(t_info *info);

int		c3_options(t_info *info, int argc, char *argv[]);
void	c3_perror(t_info *info);
void	print_error(const char *msg);

void	parse_map(t_info *info);
void	parse_args(char *arg, t_info *inf);

int		main(int argc, char *argv[]);

#endif /* CUB3D_H */
