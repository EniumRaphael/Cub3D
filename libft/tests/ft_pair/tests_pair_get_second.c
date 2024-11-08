/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_pair_get_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:15:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 17:04:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "ft_pair_types.h"
#include "tests/pair_tests.h"

int	test_pair_second(void)
{
	t_pair	pair;
	void	*a;
	void	*b;

	a = (void *)0xDEADBEEF;
	b = (void *)0xDEADDEAD;
	ft_pair_set(&pair, a, b);
	if (ft_pair_second(&pair) != b)
		return (1);
	if (ft_pair_second(NULL) != NULL)
		return (2);
	return (0);
}
