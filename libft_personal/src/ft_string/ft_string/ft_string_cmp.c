/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:50:20 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 19:27:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_cmp(const t_string *str, const char *cmp)
{
	return (ft_strcmp(str->str, cmp));
}

int	ft_string_ncmp(const t_string *str, const char *cmp, size_t n)
{
	return (ft_strncmp(str->str, cmp, n));
}

int	ft_string_cmpstr(const t_string *str, const t_string *cmp)
{
	if (str->length != cmp->length)
		return (str->length - cmp->length);
	return (ft_strcmp(str->str, cmp->str));
}

int	ft_string_ncmpstr(const t_string *str, const t_string *cmp, size_t n)
{
	if (n < str->length && n < cmp->length)
		return (ft_strncmp(str->str, cmp->str, n));
	if (str->length != cmp->length)
		return (str->length - cmp->length);
	return (ft_strcmp(str->str, cmp->str));
}
