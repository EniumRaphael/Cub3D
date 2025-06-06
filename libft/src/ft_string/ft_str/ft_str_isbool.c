/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isbool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:37:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 07:41:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdbool.h>

bool	ft_str_isbool(const char *str)
{
	if (!str)
		return (false);
	if (ft_strcmp(str, "true") == 0 || ft_strcmp(str, "false") == 0 || \
	ft_strcmp(str, "0") == 0 || ft_strcmp(str, "1") == 0)
		return (true);
	return (false);
}
