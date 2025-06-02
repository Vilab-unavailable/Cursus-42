/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:22:36 by vilabard          #+#    #+#             */
/*   Updated: 2025/06/02 18:22:44 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_puthexa(unsigned int nb)
{
	char	c;

	if (nb % 16 <= 9)
		c = '0' + (nb % 16);
	else
		c = 'a' + (nb % 16) - 10;
	nb = nb / 16;
	if (nb != 0)
		ft_puthexa(nb);
	ft_printchar(c);
}

void	ft_puthexabig(unsigned int nb)
{
	char	c;

	if (nb % 16 <= 9)
		c = '0' + (nb % 16);
	else
		c = 'A' + (nb % 16) - 10;
	nb = nb / 16;
	if (nb != 0)
		ft_puthexabig(nb);
	ft_printchar(c);
}

int	ft_hexalen(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while ((n / 16 != 0) || (n % 16 != 0))
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_printhexa(unsigned int nb, char c)
{
	if (c == 'a')
		ft_puthexa(nb);
	else if (c == 'A')
		ft_puthexabig(nb);
	return (ft_hexalen(nb));
}
