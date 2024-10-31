/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_narena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:41:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/30 18:06:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "ft_math.h"
#include <stddef.h>
#include <stdlib.h>

#define FT_NARENAS_MAX 16
#define FT_AREA_BLOCK_SIZE 4096

typedef struct s_arena
{
	void			*block_origin;
	void			*block_current;
	void			*block_end;
}	t_arena; 

t_list	*ft_arena_get(int n)
{
	static t_list	arena_array[FT_NARENAS_MAX] = {0};

	if (n < 0 || n >= FT_NARENAS_MAX)
		return (NULL);
	return (&arena_array[n]);
}

bool ft_arena_create_handler(t_list *ar_ptr, size_t size)
{
	t_arena	*arena;

	size = ft_align_2(size + sizeof(t_arena), FT_AREA_BLOCK_SIZE);
	arena = malloc(size);
	if (!arena)
		return (false);
	arena->block_origin = arena + 1;
	arena->block_current = arena->block_origin;
	arena->block_end = (void *)arena + size;
	ar_ptr->data = arena;
	return (true);
}

void *ft_arena_alloc(size_t size, int ar_nb)
{
	t_list	*ar_list;
	t_arena	*arena;
	void	*ret;

	size = ft_align_2(size, FT_AREA_BLOCK_SIZE);
	ar_list = ft_arena_get(ar_nb);
	if (!ar_list)
		return (NULL);
	arena = ft_ll_end(ar_list)->data;
	if (!arena && ft_arena_create_handler(ar_list, size) == false)
		return (NULL);
		// create new block handler - if fail ret null
	if (arena->block_origin == NULL || \
		arena->block_current + size > arena->block_end)
	{
		// allocate a new block
		;
	}
	ret = arena->block_current;
	arena->block_current += size;
	return (ret);
}
