/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:39 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 00:53:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_string.h"

int	test_memmap(void)
{
	const char	*tb[3] = {"Hello", "World", "!"};
	char		**str2;

	str2 = (char **) ft_memmap((void *)tb, sizeof(tb) / sizeof(tb[0]),
			(t_data_tr)ft_strdup);
	if (ft_strcmp(str2[0], "Hello") != 0)
		return (1);
	if (ft_strcmp(str2[1], "World") != 0)
		return (1);
	if (ft_strcmp(str2[2], "!") != 0)
		return (1);
	ft_free_2d((void **)str2);
	str2 = (char **) ft_memmap(NULL, 0, (t_data_tr)ft_strdup);
	if (str2)
		return (2);
	str2 = (char **) ft_memmap((void *)tb, 0, (t_data_tr)ft_strdup);
	if (str2)
		return (3);
	str2 = (char **) ft_memmap((void *)tb, sizeof(tb) / sizeof(tb[0]), NULL);
	if (str2)
		return (4);
	return (0);
}
