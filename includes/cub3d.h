/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:30:26 by rparodi           #+#    #+#             */
/*   Updated: 2024/10/30 17:01:03 by rparodi          ###   ########.fr       */
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

# include "message_error.h"

# ifndef BONUS
#  define BONUS 0
# endif

bool	ft_parse_args(int argc, char *argv[]);
int		main(int argc, char *argv[]);

#endif
