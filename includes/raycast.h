/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:27:30 by rparodi           #+#    #+#             */
/*   Updated: 2024/11/12 15:04:37 by rparodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <math.h>

# define MAX_RANGE 100.0
# define STEP_SIZE 0.1

/**
 * @brief Convert the degrees to radian
 *
 * @param degrees the value to convert
 * @return the value converted in radian
 */
double	cub_convert_rad_to_deg(double degrees);

#endif
