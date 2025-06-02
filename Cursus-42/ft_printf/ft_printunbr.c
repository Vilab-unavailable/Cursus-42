/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:16:50 by vilabard          #+#    #+#             */
/*   Updated: 2025/06/02 19:16:59 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putunbr(unsigned int n)
{
	char	c;

	c = '0' + (n % 10);
	n = n / 10;
	if (n != 0)
		ft_putunbr(n);
	write(1, &c, 1);
}

size_t	ft_uintlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while ((n / 10 != 0) || (n % 10 != 0))
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_printunbr(int n)
{
	ft_putunbr(n);
	return ((int)ft_uintlen(n));
}
