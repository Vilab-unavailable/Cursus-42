/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:29:54 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/25 10:47:22 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		res = res * nb;
		nb-- ;
	}
	return (res);
}
/*
#include <unistd.h>

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

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++ ;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++ ;
	}
	return (res * sign);
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_putnbr(ft_iterative_factorial(ft_atoi(argv[i])));
		write(1, "\n", 1);
		i++ ;
	}
	return(0);
}
*/
