/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strappend_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:12:40 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/02 08:08:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

// calloc sets the \0 byte at the end of the string
// we test the function can append at empty string
int	test_strappend_c(void)
{
	char	*str;

	str = ft_strdup("Hello");
	if (!str)
		return (1);
	if (ft_strappend_c(&str, ' ') == 0 || ft_strcmp(str, "Hello ") != 0)
		return (2);
	if (ft_strappend_c(&str, 'W') == 0 || ft_strcmp(str, "Hello W") != 0)
		return (3);
	if (ft_strappend_c(NULL, '\0'))
		return (4);
	free(str);
	str = ft_calloc(1, 1);
	if (!str || ft_strappend_c(&str, ' ') == 0 || ft_strcmp(str, " ") != 0)
		return (5);
	free(str);
	str = NULL;
	if (ft_strappend_c(&str, ' ') == 0 || ft_strcmp(str, " ") != 0)
		return (6);
	free(str);
	return (0);
}
