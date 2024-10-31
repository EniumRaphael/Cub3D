/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:46:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/13 17:54:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	char		*ret;
	int			i;
	const char	target = (char)c;

	ret = NULL;
	i = 0;
	while (str[i] && !ret)
	{
		if (str[i] == target)
			ret = (char *)str + i;
		i++;
	}
	if (!str[i] && target == 0)
		return ((char *)str + i);
	return ((char *)ret);
}
