/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_to_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:52:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/13 16:46:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_string.h"
#include "ft_string_types.h"

char	*ft_fd_to_buff(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*file;
	char	*prev;
	ssize_t	ret;

	if (fd == -1)
		return (NULL);
	file = NULL;
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == -1)
		return (NULL);
	buff[ret] = '\0';
	file = ft_strdup(buff);
	while (ret == BUFFER_SIZE)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (ft_free((void **)&file), NULL);
		buff[ret] = '\0';
		prev = file;
		file = ft_strjoin(file, buff);
		ft_free((void **)&prev);
	}
	return (file);
}
