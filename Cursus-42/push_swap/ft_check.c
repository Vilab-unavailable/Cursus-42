/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:55:26 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/07 17:55:35 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check for doubles and out of int
int	ft_check_values(long long *list, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!list || !list[0]
		|| (list[len - 1] < INT_MIN || list[len - 1] > INT_MAX))
		return (1);
	while (i < len - 1)
	{
		if ((list[i] < INT_MIN || list[i] > INT_MAX))
			return (1);
		j = i + 1;
		while (j < len)
		{
			if (list[j] == list[i])
				return (1);
			j++ ;
		}
		i++ ;
	}
	return (0);
}

int	ft_input_is_numeric(char **tstr)
{
	int	i;
	int	j;

	j = 0;
	while (tstr[j])
	{
		i = 0;
		if (!tstr[j][i])
			return (0);
		while (tstr[j] && tstr[j][i])
		{
			if ((tstr[j][i] < '0' || tstr[j][i] > '9')
				&& !(i == 0 && tstr[j][i] == '-' && (tstr[j][i + 1] >= '0'
					&& tstr[j][i + 1] <= '9')))
				return (0);
			i++ ;
		}
		j++ ;
	}
	return (1);
}
