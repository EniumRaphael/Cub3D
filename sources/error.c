/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:09:00 by rparodi           #+#    #+#             */
/*   Updated: 2024/10/31 11:21:59 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <string.h>

void	print_error(char *msg)
{
	write(2, BOLD_RED, strlen(BOLD_RED));
	write(2, "Error:\n", strlen("Error:\n"));
	write(2, RESET, strlen(RESET));
	write(2, RED, strlen(RED));
	write(2, msg, strlen(msg));
	write(2, RESET, strlen(RESET));
}
