/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:14:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/11/11 21:16:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <unistd.h>

int	ft_putendl_fd(const char *s, int fd)
{
	int	ret;

	if (!s)
		return (-1);
	ret = ft_putstr_fd(s, fd);
	if (ret < 0)
		return (ret);
	if (write(fd, "\n", 1) < 0)
		return (-1);
	return (ret + 1);
}
