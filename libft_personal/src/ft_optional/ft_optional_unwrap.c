/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_unwrap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:07:00 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 22:28:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"

void	*ft_optional_unwrap(t_optional opt)
{
	if (opt.pres != OPT_NONE)
		return (opt.val);
	return (NULL);
}
