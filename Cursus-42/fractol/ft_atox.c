/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:17:45 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/17 20:17:47 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long long	ft_llong_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++ ;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (INT_MIN - 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++ ;
	}
	return (res * sign);
}

double	ft_atof(const char *str)
{
	double	res1;
	double	res2;
	int		i;

	res1 = 0;
	res1 = (double)ft_atoi(str);
	res2 = 0.0;
	i = 0;
	while (str[i] && str[i] != '.')
		i++ ;
	if (str[i] && str[i] == '.' && str[i + 1]
		&& (str[i + 1] >= '0' && str[i] <= '9'))
	{
		i++ ;
		res2 = (double)ft_atoi(&str[i]);
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			res2 /= 10;
			i++;
		}
	}
	if (str[0] != '-')
		return (res1 + res2);
	else
		return (res1 - res2);
}
