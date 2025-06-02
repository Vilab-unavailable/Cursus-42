/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:49:40 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/07 11:49:42 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	i = 0;
	while (src[len])
		len++ ;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		*dup = 0;
	else
	{
		while (i < len)
		{
			dup[i] = src[i];
			i++;
		}
	}
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	i = 0;
	stock = malloc(sizeof(t_stock_str) * ac + 1);
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		i++ ;
	}
	stock[i].str = 0;
	return (stock);
}
