/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:10:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 17:40:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_arena_alloc(size_t size)
{
	return (ft_narena_alloc(size, 0));
}

void	*ft_arena_realloc(void *ptr, size_t size)
{
	return (ft_narena_realloc(ptr, size, 0));
}

void	*ft_arena_calloc(size_t count, size_t size)
{
	return (ft_narena_calloc(count, size, 0));
}

void	ft_arena_free(void *ptr)
{
	ft_narena_free(ptr, 0);
}
