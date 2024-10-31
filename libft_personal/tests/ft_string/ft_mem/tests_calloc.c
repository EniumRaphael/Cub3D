/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:23:35 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 21:40:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdint.h>

// str[x] = 'a' is to test that we can write in the memory we asked for
int	test_calloc(void)
{
	char	*str;

	str = ft_calloc(10, sizeof(char));
	str[9] = 'a';
	free(str);
	str = ft_calloc(10, sizeof(char *));
	str[9 * sizeof(char *)] = 'a';
	free(str);
	str = ft_calloc(0, sizeof(char));
	free(str);
	str = ft_calloc(SIZE_MAX, SIZE_MAX);
	if (str)
		return (1);
	return (0);
}
