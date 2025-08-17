/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:19:25 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/17 20:19:27 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_d_absolute(double nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

int	ft_is_double(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	i++ ;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i++] == '.')
			dot++ ;
		if (dot > 1)
			return (0);
	}
	if (!str[i] && dot == 1 && str[i - 1] >= '0' && str[i - 1] <= '9')
		return (1);
	else
		return (0);
}
