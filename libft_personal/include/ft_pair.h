/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:14:08 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 17:12:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR_H
# define FT_PAIR_H

/* ************************************************************************** */
/*																			  */
/* Module: FT_PAIR															  */
/* Prefix: ft_pair															  */
/*																			  */
/* This module provide a pair structure and a simple way to interact with it. */
/*																			  */
/* ************************************************************************** */

# include "ft_defs.h"
# include "ft_pair_types.h"

/// @brief Create a new pair
/// @param first The first element of the pair
/// @param second The second element of the pair
/// @return The new pair allocated
/// @note avoid this function if you can, use ft_pair_set instead with a
/// stack allocated pair.
/// @note Free with basic free call.
t_pair	*ft_pair_new(void *first, void *second);

/// @brief Set the first and second element of the pair
/// @param pair The pointer to the pair to set
/// @param first The first element of the pair
/// @param second The second element of the pair
/// @return void
void	ft_pair_set(t_pair *pair, void *first, void *second);

/// @brief Get the first element of the pair
/// @param pair The pointer to the pair
/// @return The first element of the pair
/// @note Null safe.
void	*ft_pair_first(t_pair *pair);

/// @brief Get the second element of the pair
/// @param pair The pointer to the pair
/// @return The second element of the pair
/// @note Null safe.
void	*ft_pair_second(t_pair *pair);

/// @brief Frees the pair
/// @param pair The pointer to the pair to free.
/// @param del_f The function to apply to the first elements of the pair before 
/// freeing the pair.
/// @param del_s The function to apply to the second elements of the pair before
/// freeing the pair.
/// @note The pair pointer is set to NULL.
void	ft_pair_destroy(t_pair **pair, t_data_apply del_f, t_data_apply del_s);

/// @brief Compare two pairs
/// @param pair1 The first pair to compare
/// @param pair2 The second pair to compare
/// @param cmp The comparison function to use
/// @return The result of the comparison
/// @note The comparison function should conform to the c standard,
///  aka < 0, 0 or > 0 for pair1 < pair2, pair1 == pair2 or pair1 > pair2
///	 respectively.
///	@note If no comparison function is provided, the comparison will be done
///	 on the pointer value.
int		ft_pair_cmp(t_pair *pair1, t_pair *pair2, t_data_cmp cmp);

/// @brief Compare two pairs
/// @param pair1 The first pair to compare
/// @param pair2 The second pair to compare
/// @param cmp The comparison function to use
/// @return The result of the comparison
/// @note Same as ft_pair_cmp but compare the first element of the pair
int		ft_pair_cmp_first(t_pair *pair1, t_pair *pair2, t_data_cmp cmp);

/// @brief Compare two pairs
/// @param pair1 The first pair to compare
/// @param pair2 The second pair to compare
/// @param cmp The comparison function to use
/// @return The result of the comparison
/// @note Same as ft_pair_cmp but compare the second element of the pair
int		ft_pair_cmp_second(t_pair *pair1, t_pair *pair2, t_data_cmp cmp);

#endif
