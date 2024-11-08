/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 07:41:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include <stdbool.h>

bool	ft_str_isnum(const char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (ft_str_isvalid(str + i, ft_isdigit));
}
