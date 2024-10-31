/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:33:46 by iron              #+#    #+#             */
/*   Updated: 2024/07/06 16:23:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

const t_test	*get_tests(void)
{
	static const t_test	tests[] = {
	{"string", tests_string},
	{"vec", tests_vector},
	{"map", tests_map},
	{"simply linked lists", tests_linked_list_all},
	{"doubly linked lists", tests_doubly_linked_list_all},
	{"optional", tests_optional},
	{"args", tests_args},
	{"math", tests_math},
	{"pair", tests_pair},
	{NULL, NULL}
	};

	return (tests);
}

static int	exit_msg(int collect)
{
	if (collect == 0)
		ft_putendl_fd("\033[32mAll tests passed\033[0m", STDOUT_FILENO);
	else
		ft_putendl_fd("\033[31mSome tests failed\033[0m", STDOUT_FILENO);
	return (collect != 0);
}

int	main(void)
{
	int				collect;
	int				prev;
	size_t			i;
	const t_test	*tests = get_tests();

	i = 0;
	collect = 0;
	while (tests[i].name)
	{
		prev = collect;
		ft_putstr_fd("\n\nTesting ", STDOUT_FILENO);
		ft_putendl_fd(tests[i].name, STDOUT_FILENO);
		collect += tests[i].test();
		ft_putstr_fd("\nModule:: ", STDOUT_FILENO);
		ft_putstr_fd(tests[i].name, STDOUT_FILENO);
		if (collect == prev)
			ft_putstr_fd(" \033[32mOK\033[0m\n", STDOUT_FILENO);
		else
			ft_putstr_fd(" \033[31mKO\033[0m\n", STDOUT_FILENO);
		i++;
	}
	return (exit_msg(collect));
}
