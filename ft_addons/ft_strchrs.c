/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:56:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/20 15:58:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_strchrs(const char *str, const char *chrs)
{
	while (*str)
	{
		if (ft_strchr(chrs, *str))
			return ((void *)str);
		str++;
	}
	return (NULL);
}
