/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:28:37 by vilabard          #+#    #+#             */
/*   Updated: 2025/06/02 18:28:39 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		ft_printstr("-2147483648");
	else if (n < 0)
	{
		ft_printchar('-');
		n = -n;
		ft_putnbr(n);
	}
	else
	{
		c = '0' + (n % 10);
		n = n / 10;
		if (n != 0)
			ft_putnbr(n);
		ft_printchar(c);
	}
}

size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while ((n / 10 != 0) || (n % 10 != 0))
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_printnbr(int n)
{
	ft_putnbr(n);
	return ((int)ft_intlen(n));
}
