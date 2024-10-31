/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_pair_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:09:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 16:46:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "ft_pair_types.h"
#include "tests/pair_tests.h"

int	test_pair_set(void)
{
	t_pair	pair;
	void	*a;
	void	*b;
	void	*c;

	a = (void *)0xDEADBEEF;
	b = (void *)0xDEADDEAD;
	c = (void *)0xDEADCAFE;
	ft_pair_set(&pair, a, b);
	if (pair.first != a || pair.second != b)
		return (1);
	ft_pair_set(&pair, c, a);
	if (pair.first != c || pair.second != a)
		return (1);
	ft_pair_set(NULL, a, b);
	return (0);
}
