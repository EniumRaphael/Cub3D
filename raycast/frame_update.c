/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:02:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/12 06:21:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_struct.h"

#include "mlx_functions.h"
#include "ft_string.h"

#include <unistd.h>

// Return 42 is irrelevant check mlx_loop to see that mlx doesn't care for the 
//		return of the function... 
//		(Why 'int (*)(void*)' when you dont use the int)
//
// This function is called each time the mlx loops over the mlx pointer in 
//		mlx_loop. here we do calc on time since last frame and player position 
//		to know if we need to re-draw the screen. if yes call raph function for
//		calc.
// The need to redraw can also be expressed in the diferent key_pressed 
//		functions, I would recomend to make a bool field for that in the info
//		struct.
// As a pure artefact of using mlx this function will likely be mooved to 
//		mlx_layer in the final repo.
int c3_frame_update(void *inf_ptr)
{
	t_info *info;

	info = inf_ptr;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	ft_putendl_fd("update called\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
