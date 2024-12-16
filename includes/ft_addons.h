/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addons.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 06:09:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/16 09:36:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADDONS_H

# include <stdbool.h>

// ft_addons
/// @brief Says if a value is in a range excluding the bounds
/// @param value The value to check
/// @param min The lower bound
/// @param max The upper bound
/// @return true if the value is in the range, false otherwise
bool ft_inrange_ex(int value, int min, int max);

/// @brief Says if a value is in a range including the bounds
/// @param value The value to check
/// @param min The lower bound
/// @param max The upper bound
/// @return true if the value is in the range, false otherwise
bool ft_inrange(int value, int min, int max);

#endif
