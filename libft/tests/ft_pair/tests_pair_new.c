/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_pair_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:14:03 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 17:25:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "ft_pair_types.h"
#include "tests/pair_tests.h"

int	test_pair_new(void)
{
	t_pair	*pair;
	void	*a;
	void	*b;

	a = (void *)0xDEADBEEF;
	b = (void *)0xDEADDEAD;
	pair = ft_pair_new(NULL, NULL);
	if (!pair)
		return (1);
	if (pair->first || pair->second)
		return (2);
	ft_pair_set(pair, a, b);
	if (pair->first != a || pair->second != b)
		return (3);
	ft_pair_destroy(&pair, NULL, NULL);
	return (0);
}
