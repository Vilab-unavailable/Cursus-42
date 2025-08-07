/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:56:01 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/07 17:56:07 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freetable(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

int	ft_absolute(int nbr)
{
	if (nbr < 0 && nbr != INT_MIN)
		nbr = -nbr;
	return (nbr);
}

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

// return the number of line in the table, ie the len of the list of int
size_t	ft_len_tchar(char **tchar)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (tchar[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_dup_table(char **tab)
{
	size_t	len;
	size_t	i;
	char	**newtab;

	len = ft_len_tchar(tab);
	newtab = ft_calloc((len + 1), sizeof(char **));
	i = 0;
	while (i < len)
	{
		newtab[i] = ft_strdup(tab[i]);
		i++ ;
	}
	return (newtab);
}
