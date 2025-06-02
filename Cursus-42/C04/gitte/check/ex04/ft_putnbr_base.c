/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:36:21 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/08 13:26:21 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			else if (base[i] == '+' || base[i] == '-' || base[j] == '+'
				|| base[j] == '-')
				return (0);
			j++ ;
		}
		i++ ;
	}
	if (i >= 2)
		return (i);
	else
		return (0);
}

void	ft_putnbr_base_core(int nbr, char *base, int len_base)
{
	char	c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		c = base[(nbr % len_base) * (-1)];
		nbr = -(nbr / len_base);
		ft_putnbr_base_core(nbr, base, len_base);
	}
	else if (nbr / len_base != 0)
	{
		c = base[nbr % len_base];
		ft_putnbr_base_core(nbr / len_base, base, len_base);
	}
	else
		c = base[nbr % len_base];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len_base;

	len_base = ft_check_base(base);
	if (len_base >= 2)
	{
		ft_putnbr_base_core(nbr, base, len_base);
	}
}
/*
int	main(void)
{
	int	nb;
	char *base1 = "0123456789";
	char *base2 = "01";
	char *base3 = "0123456789abcdef";
	

	nb = 0;
	ft_putnbr_base(nb, base1);
	write(1, "\n", 1);
	nb = 00;
	ft_putnbr_base(nb, base3);
	write(1, "\n", 1);
	nb = 5;
	ft_putnbr_base(nb, base2);
	write(1, "\n", 1);
	nb = -2147483648;
	ft_putnbr_base(nb, base2);
	write(1, "\n", 1);
	return (0);
}
*/
