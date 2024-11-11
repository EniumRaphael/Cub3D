/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:23 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/11 21:17:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_replace(t_string *str, const char *to_replace, \
	const char *replace_by)
{
	char	*tmp;
	char	*tmp2;

	tmp = (char *)ft_string_get(str);
	if (!tmp)
		return (0);
	tmp2 = ft_str_replace(tmp, to_replace, replace_by);
	if (!tmp2)
		return (0);
	ft_string_set_inplace(str, tmp2);
	return (1);
}

int	ft_string_replace_chr(t_string *str, char to_replace, char replace_by)
{
	size_t	i;
	size_t	nb_rep;

	if (!str->str)
		return (0);
	i = 0;
	nb_rep = 0;
	while (i < str->length)
	{
		if (str->str[i] == to_replace)
		{
			str->str[i] = replace_by;
			nb_rep++;
		}
		i++;
	}
	if (nb_rep == 0)
		return (0);
	return (1);
}
