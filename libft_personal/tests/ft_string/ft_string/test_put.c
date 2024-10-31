/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:45:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/03 10:27:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

static int	normal_cases(void)
{
	t_string	*str;
	const char	*src;
	char		*res;
	int			fd;
	const char	*file = TESTS_FPREFIX "test_string_put.txt";

	src = "Hello world this is zod!";
	str = ft_string_from(src);
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_string_put(str, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (2);
	res = ft_fd_to_buff(fd);
	destroy_test_file(fd, file);
	if (ft_strcmp(src, res) != 0)
		return (3);
	return (free(res), ft_string_destroy(&str), 0);
}

static int	error_case(void)
{
	t_string	*str;
	const int	fd = -1;

	str = ft_string_from("Hello");
	if (ft_string_put(str, fd) != -1)
		return (1);
	if (ft_string_put(NULL, STDOUT_FILENO) != -1)
		return (2);
	ft_free((void **)&str->str);
	if (ft_string_put(str, STDOUT_FILENO) != -1)
		return (3);
	str->str = NULL;
	str->length = 0;
	if (ft_string_put(str, STDOUT_FILENO) != 0)
		return (4);
	return (ft_string_destroy(&str), 0);
}

int	test_string_put(void)
{
	int	ret;

	ret = normal_cases();
	if (ret)
		return (ret);
	ret = error_case();
	if (ret)
		return (ret + 10);
	return (0);
}
