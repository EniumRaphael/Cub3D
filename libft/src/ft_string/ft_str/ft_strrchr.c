/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:46:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/13 17:54:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	char		*ret;
	int			i;
	const char	target = (char)c;

	ret = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == target)
			ret = (char *)str + i;
		i++;
	}
	if (str[i] == target)
		return ((char *)str + i);
	return (ret);
}
