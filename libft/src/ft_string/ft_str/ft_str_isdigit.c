/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:39:43 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 07:40:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include <stdbool.h>

bool	ft_str_isdigit(const char *str)
{
	if (!str)
		return (false);
	return (ft_str_isvalid(str, ft_isdigit));
}
