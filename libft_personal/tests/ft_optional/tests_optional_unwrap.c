/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_optional_unwrap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:32:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 22:30:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	test_optional_unwrap(void)
{
	t_optional	opt;
	int			*ptr;

	opt.pres = OPT_SOME;
	ptr = malloc(sizeof(int));
	*ptr = 42;
	opt.val = ptr;
	if (ft_optional_unwrap(opt) != ptr)
		return (1);
	free(ptr);
	opt.pres = OPT_NONE;
	opt.val = (void *)0xDEADBEEF;
	if (ft_optional_unwrap(opt) != NULL)
		return (2);
	return (0);
}
