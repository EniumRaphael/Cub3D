/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:41:32 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/09 01:21:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "ft_string.h"

/**
 * @brief checking if the args given to the executable is valid
 *
 * @param argc the arguments count
 * @param argv the arguments value
 * @return false if an error / true if no error
 */
void	parse_args(char *arg, t_info *inf)
{
	if (arg == NULL && inf->cli_ctx.file == NULL)
		return (inf->last_error = ERROR_MISSING_FILE, (void)0);
	if (arg && ft_strlen(arg) < 5)
		return (inf->last_error = ERROR_NAME_FILE, (void)0);
	if (arg && ft_strend_with(arg, FILE_EXTENSION) == false)
		return (inf->last_error = ERROR_EXTENSION_FILE, (void)0);
	if (arg && inf->cli_ctx.file == NULL)
		inf->cli_ctx.file = ft_strdup(arg);
	inf->last_error = NO_ERROR;
}
