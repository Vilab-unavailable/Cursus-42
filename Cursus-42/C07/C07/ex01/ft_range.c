/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:50:37 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/02 22:36:10 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*range;
	int	i;

	if (max <= min)
		return (NULL);
	else
	{
		len = max - min;
		range = malloc(len * sizeof(int));
		i = 0;
		while (i < len)
		{
			range[i] = min + i;
			i++ ;
		}
	}
	return (range);
}
/*
#include <unistd.h>
#include <string.h>

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

void	ft_puttab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		i++ ;
	}
}

int	main(void)
{
	int *buff;

	buff = ft_range(1, 9);
	ft_puttab(buff, 8);
	write(1, " \n", 1);
	buff = ft_range(-3, 3);
	ft_puttab(buff, 6);
	write(1, "\n", 1);
	buff = ft_range(10, 9);
	ft_puttab(buff, 1);
	write(1, "\n", 1);
	return (0);
}
*/
