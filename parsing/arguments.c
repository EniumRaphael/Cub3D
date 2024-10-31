/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:41:32 by rparodi           #+#    #+#             */
/*   Updated: 2024/10/31 16:54:21 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief checking if the args given to the executable is valid
 *
 * @param argc the arguments count
 * @param argv the arguments value
 * @return false if an error / true if no error
 */
bool	ft_parse_args(int argc, char *argv[])
{
	if (argc != 2)
		return (print_error(ERR_ARGS_COUNT), false);
	if (ft_strlen(argv[1]) < 4 || \
		ft_strcmp((argv[1] + (strlen(argv[1]) - 4)), ".cub") != 0)
		return (print_error(INV_NAME_MAP), false);
	return (true);
}
