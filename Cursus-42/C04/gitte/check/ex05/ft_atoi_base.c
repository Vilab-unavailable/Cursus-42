/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:40:07 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/08 13:28:17 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			else if (base[i] == '+' || base[i] == '-' || base[j] == '+'
				|| base[j] == '-')
				return (0);
			else if ((base[i] >= 8 && base[i] <= 13) || (base[j] >= 8
					&& base[j] <= 13) || base[i] == 32 || base[j] == 32)
				return (0);
			j++ ;
		}
		i++ ;
	}
	if (i >= 2)
		return (i);
	else
		return (0);
}

int	ft_atoi_base_core(char *str, char *base, int base_len)
{
	int		i;
	int		j;
	int		res;
	char	in_base;

	i = 0;
	in_base = 'y';
	res = 0;
	while (in_base == 'y')
	{
		j = 0;
		while (base[j] && base[j] != str[i])
		{
			j++ ;
			if (base[j] == '\0')
				in_base = 'n';
		}
		if (in_base == 'y')
			res = res * base_len + j;
		i++ ;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;
	int	base_len;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++ ;
	}
	base_len = ft_check_base(base);
	if (base_len >= 2)
		res = ft_atoi_base_core(&str[i], base, base_len);
	return (res * sign);
}
/*
#include<unistd.h>

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

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
		i = ft_atoi_base(argv[1], argv[2]);
	ft_putnbr(i);
	return (i);
}
*/
