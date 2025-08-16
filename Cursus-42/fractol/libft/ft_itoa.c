/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:54:48 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/26 20:54:50 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
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

char	*ft_fillnbr(int long nb, char *res, size_t len)
{
	char	c;

	if (nb < 0)
	{
		res[0] = '-';
		return (ft_fillnbr(-nb, res, len));
	}
	else
	{
		c = '0' + (nb % 10);
		nb = nb / 10;
		if (nb != 0)
			ft_fillnbr(nb, res, len - 1);
		res[len] = c;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_intlen(n);
	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (res);
	res = ft_fillnbr(n, res, len - 1);
	return (res);
}
