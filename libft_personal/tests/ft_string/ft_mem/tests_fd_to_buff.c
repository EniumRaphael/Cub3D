/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_fd_to_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:15:20 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/26 19:34:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

static int	base_case(void)
{
	char	buff[100];
	char	*ret;
	int		fd;

	ft_bzero(buff, 100);
	ft_strlcat(buff, "Hello World\n\n\n\n\tv\vjkldqskjfsldfjsmldfkj\n", 100);
	fd = open(TESTS_FPREFIX "test_fd_to_buff.txt", O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (1);
	write(fd, buff, ft_strlen(buff));
	close(fd);
	fd = open(TESTS_FPREFIX "test_fd_to_buff.txt", O_RDONLY | O_CREAT);
	if (fd < 0)
		return (2);
	ret = ft_fd_to_buff(fd);
	if (ft_strcmp(ret, buff) != 0)
		return (3);
	destroy_test_file(fd, TESTS_FPREFIX "test_fd_to_buff.txt");
	return (free(ret), 0);
}

static int	error_case(void)
{
	char	*ret;
	int		bad_fd;

	bad_fd = -1;
	ret = ft_fd_to_buff(bad_fd);
	if (ret)
		return (1);
	bad_fd = open(TESTS_FPREFIX "test_fd_to_buff.txt", O_CREAT, 0004);
	if (bad_fd < 0)
		return (2);
	close(bad_fd);
	bad_fd = open(TESTS_FPREFIX "test_fd_to_buff.txt", O_RDONLY);
	ret = ft_fd_to_buff(bad_fd);
	if (ret)
		return (3);
	destroy_test_file(bad_fd, TESTS_FPREFIX "test_fd_to_buff.txt");
	return (0);
}

int	test_fd_to_buff(void)
{
	int	ret;

	ret = base_case();
	if (ret != 0)
		return (ret);
	ret = error_case();
	if (ret != 0)
		return (ret + 10);
	return (0);
}
