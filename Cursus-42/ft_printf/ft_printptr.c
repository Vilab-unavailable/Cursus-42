/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:18:45 by vilabard          #+#    #+#             */
/*   Updated: 2025/06/02 18:18:47 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putullhexa(unsigned long long nb)
{
	char	c;

	if (nb % 16 <= 9)
		c = '0' + (nb % 16);
	else
		c = 'a' + (nb % 16) - 10;
	nb = nb / 16;
	if (nb != 0)
		ft_putullhexa(nb);
	ft_printchar(c);
}

int	ft_ullhexalen(unsigned long long n)
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

int	ft_printptr(void *ptr)
{
	if (ptr == 0)
		return (ft_printstr("(nil)"));
	ft_printstr("0x");
	ft_putullhexa((unsigned long long) ptr);
	return (2 + ft_ullhexalen((unsigned long long) ptr));
}
