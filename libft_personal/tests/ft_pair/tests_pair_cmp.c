/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_pair_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:20:58 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/21 21:43:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pair.h"
#include "ft_pair_types.h"
#include "tests/pair_tests.h"
#include "tests/tests_lambda_functions.h"

static int	test_ptr(void)
{
	t_pair	pair_a;
	t_pair	pair_b;
	void	*a;
	void	*b;
	void	*c;

	a = (void *)0xDEADBEEF;
	b = (void *)0xDEADDEAD;
	c = (void *)0xDEADCAFE;
	ft_pair_set(&pair_a, a, b);
	ft_pair_set(&pair_b, c, a);
	if (ft_pair_cmp(&pair_a, &pair_b, NULL) == 0)
		return (1);
	if (ft_pair_cmp(&pair_a, &pair_a, NULL) != 0)
		return (2);
	if (ft_pair_cmp(&pair_b, &pair_a, NULL) == 0)
		return (3);
	if (ft_pair_cmp(NULL, &pair_a, NULL) == 0 || ft_pair_cmp(&pair_a, NULL,
			NULL) == 0)
		return (4);
	if (ft_pair_cmp(NULL, NULL, NULL) != 0)
		return (5);
	return (0);
}

static int	test_cmp(void)
{
	t_pair	pair_a;
	t_pair	pair_b;
	long	a;
	long	b;
	long	c;

	a = 21;
	b = 42;
	c = 420;
	ft_pair_set(&pair_a, (void *)a, (void *)b);
	ft_pair_set(&pair_b, (void *)c, (void *)a);
	if (ft_pair_cmp(&pair_a, &pair_b, &cmp_int) == 0)
		return (1);
	return (0);
}

int	test_pair_cmp(void)
{
	int	ret;

	ret = test_ptr();
	if (ret != 0)
		return (ret);
	ret = test_cmp();
	if (ret != 0)
		return (ret + 10);
	return (0);
}
