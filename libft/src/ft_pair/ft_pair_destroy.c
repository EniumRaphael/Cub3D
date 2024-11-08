/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:04:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/06 17:13:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_pair_types.h"
#include "ft_string.h"

void	ft_pair_destroy(t_pair **pair, t_data_apply del_f, t_data_apply del_s)
{
	if (!pair)
		return ;
	if (del_f)
		del_f((*pair)->first);
	if (del_s)
		del_s((*pair)->second);
	ft_free((void **)pair);
}
