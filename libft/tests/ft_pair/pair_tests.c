/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:53:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 17:15:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/pair_tests.h"
#include "tests/tests.h"

int	tests_pair(void)
{
	int				collect;
	const t_test	test[] = {
	{"test_pair_set", test_pair_set},
	{"test_pair_new", test_pair_new},
	{"test_pair_second", test_pair_second},
	{"test_pair_first", test_pair_first},
	{"test_pair_cmp", test_pair_cmp},
	{"test_pair_cmp_first", test_pair_cmp_first},
	{"test_pair_cmp_second", test_pair_cmp_second},
	{"tests_pair_destroy", tests_pair_destroy},
	{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
