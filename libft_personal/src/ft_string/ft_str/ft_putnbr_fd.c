/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:08:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/19 21:28:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

#include "ft_string.h"

int	ft_putnbr_fd(int nb, int fd)
{
	char	result[13] = {0};
	int		it;
	int		neg;

	neg = 0;
	it = 12;
	if (nb == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	while (nb >= 10)
	{
		result[--it] = nb % 10 + '0';
		nb /= 10;
	}
	result[--it] = nb + '0';
	if (neg)
		result[--it] = '-';
	return (ft_putstr_fd(result + it, fd));
}
