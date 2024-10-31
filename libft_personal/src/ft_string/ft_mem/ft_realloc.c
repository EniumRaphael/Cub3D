/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:27:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/19 18:16:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

// direct call to ft_malloc as ft_bzero is not needed
//  >> we are copying the content of ptr to new
void	*ft_realloc(void *ptr, size_t sizeNew, size_t sizeOld)
{
	void	*new;

	if (sizeNew == sizeOld)
		return (ptr);
	new = ft_malloc(sizeNew);
	if (!new)
		return (NULL);
	if (sizeNew < sizeOld)
		ft_memcpy(new, ptr, sizeNew);
	else
		ft_memcpy(new, ptr, sizeOld);
	free(ptr);
	return (new);
}
