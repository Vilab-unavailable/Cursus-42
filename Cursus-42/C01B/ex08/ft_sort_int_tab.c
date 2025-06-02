/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:32:03 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/30 10:57:03 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	char	again;

	again = 'y';
	while (again == 'y')
	{
		i = 0;
		again = 'n';
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				again = 'y';
			}
			i++ ;
		}
	}
}
/*
#include <unistd.h>
int	main(void)
{
	int tab[10] = {9, 5, 1, 6, 0, 8, 7, 4, 2, 3};
	int	i;
	char	c;
	
	i = 0;
	while (i < 10)
	{
		c = '0' + tab[i];
		write(1, &c, 1);
		i++ ;
	}
	write(1, "\n", 1);
	ft_sort_int_tab(tab, 10);
	i = 0;
	while (i < 10)
	{
		c = '0' + tab[i];
		write(1, &c, 1);
		i++ ;
	}
	return (0);
}
*/
