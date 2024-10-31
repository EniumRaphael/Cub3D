/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:41:32 by rparodi           #+#    #+#             */
/*   Updated: 2024/10/31 10:37:56 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <string.h>

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
		return (write(2, ERR_ARGS_COUNT, strlen(ERR_ARGS_COUNT)), false);
	if (strlen(argv[1]) < 4 || \
		strcmp((argv[1] + (strlen(argv[1]) - 4)), ".cub") != 0)
		return (write(2, INV_NAME_MAP, strlen(INV_NAME_MAP)), false);
	return (true);
}
