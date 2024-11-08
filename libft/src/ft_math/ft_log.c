/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:09:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 18:27:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ullogof(unsigned long long nbr, int base)
{
	const unsigned long long	bul = (unsigned long long)base;
	int							pow;

	pow = -1;
	while (nbr)
	{
		nbr /= bul;
		pow++;
	}
	return (pow);
}

int	ft_llogof(long long nbr, int base)
{
	if (nbr <= 0)
		return (-1);
	return (ft_ullogof((unsigned long long)nbr, base));
}

int	ft_logof(int nbr, int base)
{
	if (nbr <= 0)
		return (-1);
	return (ft_llogof((long long)nbr, base));
}

int	ft_log(int nbr)
{
	return (ft_logof(nbr, 10));
}
