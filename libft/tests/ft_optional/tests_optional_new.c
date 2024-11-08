/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_optional_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:31:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/17 22:39:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"

int	test_optional_new(void)
{
	t_optional	*opt;

	opt = ft_optional_new();
	if (!opt)
		return (1);
	if (opt->pres != OPT_NONE)
		return (2);
	if (opt->val)
		return (3);
	ft_optional_destroy(opt);
	return (0);
}
