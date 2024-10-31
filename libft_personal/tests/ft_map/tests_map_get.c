/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:14:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 18:28:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	// search for a non existing key
	ret = ft_map_get(map, "key2", strlen("key2") + 1);
	---
	// search for a non existing key in a full map
	map = ft_map_create(1);
*/

#include "ft_map.h"
#include "ft_map_types.h"
#include "ft_string.h"
#include <stdlib.h>

int	test_map_get_ultra_small(void)
{
	char		*str[2];
	t_map		*map;
	void		*ret;

	str[0] = ft_strdup("value");
	str[1] = ft_strdup("value2");
	map = ft_map_create(1);
	ft_map_set(map, "key", str[0], ft_strlen("key"));
	ft_map_set(map, "key2", str[1], ft_strlen("key"));
	ret = ft_map_get(map, "key", ft_strlen("key"));
	if (!ret)
		return (1);
	else if (ft_strcmp((char *)ret, "value"))
		return (2);
	ret = ft_map_get(map, "key2", ft_strlen("key2"));
	if (!ret)
		return (3);
	else if (ft_strcmp((char *)ret, "value2"))
		return (4);
	ft_map_destroy_free(map, free);
	return (0);
}

int	test_map_normal(void)
{
	char		*str;
	t_map		*map;
	void		*ret;

	str = ft_strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, ft_strlen("key"));
	ret = ft_map_get(map, "key", ft_strlen("key"));
	if (!ret)
		return (1);
	else if (ft_strcmp((char *)ret, "value"))
		return (2);
	ret = ft_map_get(map, "key2", ft_strlen("key2"));
	if (ret)
		return (3);
	ft_map_destroy(map);
	free(str);
	return (0);
}

int	test_map_get(void)
{
	int	ret;

	ret = test_map_get_ultra_small();
	if (ret != 0)
		return (ret + 10 * 0);
	ret = test_map_normal();
	if (ret != 0)
		return (ret + 10 * 1);
	return (0);
}
