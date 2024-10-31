/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 10:19:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_TYPES_H
# define FT_STRING_TYPES_H

# include <stddef.h>

// maximum number of file descriptors
//  - get_next_line
# ifndef MAX_FD
#  ifdef TEST
#   define MAX_FD 5
#  else
#   define MAX_FD 1024
#  endif
# endif

// default allocation size for t_strings
//  - ft_string_new
# ifndef T_STRING_BUFF
#  ifdef TEST
#   define T_STRING_BUFF 5
#  else
#   define T_STRING_BUFF 4096
#  endif
# endif

// buffer size for temporary read buffers
//  - get_next_line
//  - ft_fd_to_buff
# ifndef BUFFER_SIZE
#  ifdef TEST
#   define BUFFER_SIZE 5
#  else
#   define BUFFER_SIZE 4096
#  endif
# endif

/// @brief Structure representing a string
/// @param str The string
/// @param length The length of the string
/// @param capacity The capacity of the string
typedef struct s_string
{
	char	*str;
	size_t	length;
	size_t	capacity;
}			t_string;

#endif /* FT_STRING_TYPES_H */
