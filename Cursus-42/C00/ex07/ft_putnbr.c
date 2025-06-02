/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:04:03 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/17 14:04:12 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else
	{
		c = '0' + (nb % 10);
		nb = nb / 10;
		if (nb != 0)
			ft_putnbr(nb);
		write(1, &c, 1);
	}
}
/*
int	main(void)
{
	int	nb;

	nb = -214748364;
	ft_putnbr(nb);
	return (0);
}
*/
