/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:28:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/19 18:15:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "ft_pair_types.h"
#include "ft_string.h"
#include <stdlib.h>

t_pair	*ft_pair_new(void *a, void *b)
{
	t_pair	*ret;

	ret = ft_malloc(sizeof(*ret));
	if (!ret)
		return (NULL);
	return (ft_pair_set(ret, a, b), ret);
}
