/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:59:37 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/21 21:38:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

/* ************************************************************************** */
/*                                                                            */
/* Module: FT_MATH                                                            */
/* Prefix: ft_*																  */
/*                                                                            */
/* The FT_MATH module provides a way to handle task or queries related		  */
/*		to arithmetic operations.											  */
/*                                                                            */
/* ************************************************************************** */

# include "ft_math_types.h"
# include <stddef.h>

/// @brief Return the nearest aligned value of size on the alignment
/// @param size The size to align
/// @param alignment The alignment to use
/// @return The aligned value of size on the alignment
/// @note Optimized for power of 2 alignment
size_t		ft_align_2(size_t size, size_t alignment);

/// @brief Return the nearest aligned value of size on the alignment
/// @param size The size to align
/// @param alignment The alignment to use
/// @return The aligned value of size on the alignment
/// @note See: ft_align_2 for an optimized version for power of 2
size_t		ft_align(size_t size, size_t alignment);

/// @brief return the logaritm of the number in the specified base
/// @param nbr number to get the logaritm
/// @param base base of the logaritm
/// @return the logaritm of the number in the specified base. in case of error
/// return -1
int			ft_llogof(long long nbr, int base);

/// @brief return the logaritm of the number in the specified base
/// @param nbr number to get the logaritm
/// @param base base of the logaritm
/// @return the logaritm of the number in the specified base. in case of error
/// return -1
int			ft_ullogof(unsigned long long nbr, int base);

/// @brief return the logaritm of the number in the specified base
/// @param nbr number to get the logaritm
/// @param base base of the logaritm
/// @return the logaritm of the number in the specified base. in case of error
/// return -1
int			ft_logof(int nbr, int base);

/// @brief return the logaritm of the number in the specified base
/// @param nbr number to get the logaritm
/// @param base base of the logaritm
/// @return the logaritm of the number in the specified base. in case of error
/// return -1
int			ft_log(int nbr);

/// @brief returns the minimum of a and b
/// @param a first number
/// @param b second number
/// @return the smallest between a and b
int			ft_min(int a, int b);

/// @brief returns the maximum of a and b
/// @param a first number
/// @param b second number
/// @return the biggest between a and b
int			ft_max(int a, int b);

/// @brief Clamp a value between a minimum and a maximum
/// @param value The value to clamp
/// @param min The minimum value
/// @param max The maximum value
/// @return The clamped value between or at the minimum or maximum
/// @note This is a clamp function aka inferior and superior to min and max
/// are set to min and max
/// @file ft_clamp.c
int			ft_clamp(int value, int min, int max);

/// @brief Clamp a value between a minimum and a maximum
/// @param value The value to clamp
/// @param min The minimum value
/// @param max The maximum value
/// @return The clamped value between or at the minimum or maximum
/// @note See ft_clamp.
/// @file ft_clamp.c
float		ft_clamp_f(float value, float min, float max);

/// @brief Clamp a value between a minimum and a maximum
/// @param value The value to clamp
/// @param min The minimum value
/// @param max The maximum value
/// @return The clamped value between or at the minimum or maximum
/// @note See ft_clamp.
/// @file ft_clamp.c
double		ft_clamp_d(double value, double min, double max);

/// @brief Take a value in a range and puts it in another range of 1 to new_max
/// @param value The value to range
/// @param min The minimum value of the range
/// @param max The maximum value of the range
/// @param new_max The maximum value of the new range
/// @return The value ranged between 1 and new_max
int			ft_range(int value, int min, int max, int new_max);

/// @brief Take a value in a range and puts it in another range of 1 to new_max
/// @param value The value to range
/// @param min The minimum value of the range
/// @param max The maximum value of the range
/// @param new_max The maximum value of the new range
/// @return The value ranged between 1 and new_max
/// @note See ft_range.
float		ft_range_f(float value, float min, float max, float new_max);

/// @brief Take a value in a range and puts it in another range of 1 to new_max
/// @param value The value to range
/// @param min The minimum value of the range
/// @param max The maximum value of the range
/// @param new_max The maximum value of the new range
/// @return The value ranged between 1 and new_max
/// @note See ft_range.
double		ft_range_d(double value, double min, double max, double new_max);

/// @brief Return the absolute value of a
/// @param a The value to get the absolute value
/// @return The absolute value of a
int			ft_abs(int a);

/// @brief Return the rounded value of x
/// @param x The value to round
/// @return The rounded value of x
/// @note This function round the value to the nearest integer
double		ft_round(double x);

/// @brief Return the power of a number x to the power of y
/// @param x The number to power
/// @param y The power
/// @return The result of x to the power of y
size_t		ft_pow(size_t x, size_t y);

/// @brief Return the root square of a number
/// @param nb The number to get the root square
/// @return The root square of nb
/// @note This function use the newton's method to get the root square
/// @note If nb is negative, return -1
/// @file ft_sqrt.c
double		ft_sqrt(double nb);

/// @brief Return the absolute value of a
/// @param a The value to get the absolute value
/// @return The absolute value of a
/// @note See ft_abs.
double		ft_complex_abs(t_complex nb);

/// @brief Add a long to a complex number
/// @param nb The complex number to add the factor
/// @param factor The factor to add to the complex number
/// @return The complex number with the factor added
/// @note See ft_complex_addl.
t_complex	ft_complex_addl(t_complex nb, long factor);

/// @brief Multiply a complex number by a long
/// @param nb The complex number to multiply
/// @param factor The factor to multiply the complex number
/// @return The complex number multiplied by the factor
t_complex	ft_complex_mull(t_complex nb, long factor);

/// @brief Multiply a complex number by a double
/// @param nb The complex number to multiply
/// @param factor The factor to multiply the complex number
/// @return The complex number multiplied by the factor
t_complex	ft_complex_muld(t_complex nb, double factor);

#endif
