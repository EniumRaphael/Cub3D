/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isoct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:49:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 07:41:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"

bool	ft_str_isoct(const char *str)
{
	if (!str)
		return (false);
	if (!ft_strstart_with(str, "0o") && !ft_strstart_with(str, "0O"))
		return (false);
	return (ft_str_isvalid(str + 2, ft_isoctdigit));
}
