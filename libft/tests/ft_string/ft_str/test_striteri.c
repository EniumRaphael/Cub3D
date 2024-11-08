/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:39:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 08:11:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static void	local_iteri(unsigned int i, char *c)
{
	*c = 'a';
	(void)i;
}

// last 2 calls are to test NULL protection
int	test_striteri(void)
{
	char	str[20];

	ft_strlcpy(str, "Hello World!", 20);
	ft_striteri(str, &local_iteri);
	if (ft_strcmp(str, "aaaaaaaaaaaa") != 0)
		return (1);
	ft_striteri(NULL, &local_iteri);
	ft_striteri(str, NULL);
	return (0);
}
