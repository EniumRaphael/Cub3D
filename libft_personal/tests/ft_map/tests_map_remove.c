/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:18:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 18:31:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_string.h"
#include "ft_map_types.h"
#include "ft_string.h"
#include <stdlib.h>

static int	test_map_remove_normal(void)
{
	char	*str;
	void	*ret;
	t_map	*map;

	str = ft_strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, ft_strlen("key"));
	ret = ft_map_remove(map, "key", ft_strlen("key"));
	if (!ret)
		return (1);
	else if (ret != str)
		return (2);
	ret = ft_map_remove(map, "key2", ft_strlen("key2"));
	if (ret)
		return (3);
	ft_map_destroy(map);
	free(str);
	return (0);
}

static int	test_map_remove_colision(void)
{
	const char	*keys[] = {"key", "key2", "key3", "key4", NULL};
	const char	*str[] = {
		ft_strdup("value"), ft_strdup("value2"), ft_strdup("value3"),
		ft_strdup("value4"), NULL};
	t_map		*map;
	int			ret;

	map = ft_map_create(1);
	ret = 0;
	while (str[ret])
	{
		ft_map_set(map, keys[ret], str[ret], ft_strlen(keys[ret]));
		ret++;
	}
	ret = 0;
	if (ft_map_remove(map, keys[2], ft_strlen(keys[2])) != str[2])
		return (1);
	if (ft_map_remove(map, keys[1], ft_strlen(keys[1])) != str[1])
		return (2);
	if (ft_map_remove(map, keys[0], ft_strlen(keys[0])) != str[0])
		return (3);
	if (ft_map_remove(map, keys[3], ft_strlen(keys[3])) != str[3])
		return (4);
	return (ft_map_destroy(map), ft_apply_2d((void **)str, free), 0);
}

int	test_map_remove(void)
{
	int	ret;

	ret = test_map_remove_normal();
	if (ret != 0)
		return (ret);
	ret = test_map_remove_colision();
	if (ret != 0)
		return (ret + 10);
	return (0);
}
