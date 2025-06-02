/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:09:05 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/08 18:09:08 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int	*tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	res = malloc(length * sizeof(int));
	if (res == NULL)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++ ;
	}
	return (res);
}
/*
int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i < 46341 && i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++ ;
	}
	return (0);
}

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

int	main(void)
{
	int tab[10] = {9, 5, 25, 6, 0, 81, 7, 4, 2, 93};
	int *r;
	int	i;
	
	r = ft_map(tab, 10, &ft_sqrt);
	i = 0;
	while (i < 10)
		ft_putnbr(r[i++]);
	free(r);
	return(0);
}
*/
