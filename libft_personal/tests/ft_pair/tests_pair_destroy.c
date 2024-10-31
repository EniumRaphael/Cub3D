/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_pair_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:09:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 17:16:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/pair_tests.h"
#include "ft_pair_types.h"
#include "ft_pair.h"

int	tests_pair_destroy(void)
{
	t_pair	*pair;

	pair = ft_pair_new("key", "value");
	ft_pair_destroy(&pair, NULL, NULL);
	if (pair != NULL)
		return (1);
	pair = ft_pair_new(ft_strdup("key"), ft_strdup("value"));
	ft_pair_destroy(&pair, &free, &free);
	if (pair != NULL)
		return (2);
	ft_pair_destroy(NULL, NULL, NULL);
	pair = NULL;
	ft_pair_destroy(&pair, NULL, NULL);
	return (0);
}
