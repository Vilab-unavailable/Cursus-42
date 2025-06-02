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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++ ;
	}
	dest[len + i] = '\0';
	return (dest);
}

unsigned int	ft_strlen_unsigned(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++ ;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_s;
	unsigned int	len_d;

	len_s = ft_strlen_unsigned(src);
	len_d = ft_strlen_unsigned(dest);
	if ((len_s + len_d) > (size - 1))
		return (size);
	else
	{
		ft_strcat(dest, src);
		return (len_s + len_d);
	}
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
