/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:36:58 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/30 11:37:41 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		len = max - min;
		*range = malloc((len + 1) * sizeof(int));
		if (*range == NULL)
			return (-1);
		i = 0;
		while (i < len)
		{
			range[0][i] = min + i;
			i++ ;
		}
	}
	return (len);
}
/*
#include <unistd.h>
#include <string.h>
#include <stdio.h>
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
	while (i < size && tab[i])
	{
		ft_putnbr(tab[i]);
		i++ ;
	}
}

int	main(void)
{
	char len;
	int *tab;
	int min = 5;
	int max = 5;

	tab = malloc(1 * sizeof(int));
	if (tab == NULL)
		return (-1);
	len = 0;
	len = '0' + ft_ultimate_range(&tab, min, max);
	write(1, &len, 1);
	if (len != '0')
		ft_puttab(tab, max - min);
	return (0);
}
*/
