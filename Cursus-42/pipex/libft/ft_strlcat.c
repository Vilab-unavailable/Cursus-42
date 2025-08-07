/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:32:32 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/24 13:15:26 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[j] && j < size)
		j++;
	while (src[i] && (j + i < size - 1))
	{
		dst[j + i] = src[i];
		i++ ;
	}
	if (j + i < size)
		dst[j + i] = '\0';
	return (j + ft_strlen(src));
}
/*
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++ ;
	}
}

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
	char str[] = "1234";
	char str3[] = "1234";
	ft_putstr(str3);
	write(1, "\n", 1);
	ft_putnbr(ft_strlcat(str3, str, 40));
	write(1, "\n", 1);
	ft_putstr(str3);
	
	return (0);
}
*/
