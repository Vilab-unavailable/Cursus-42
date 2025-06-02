/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:19:54 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/30 10:58:09 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size)
	{
		temp = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = temp;
		size-- ;
		i++ ;
	}
}
/*
int		main(void)
{
	int tab[10] = {0,1,2,3,4,5,6,7,8,9};

	printf("9,8,7,6,5,4,3,2,1,0:");
	ft_rev_int_tab(tab, 10);
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", tab[0],
       		tab[1], tab[2], tab[3], tab[4], tab[5], tab[6],
	       tab[7], tab[8], tab[9]);
}
*/
/*
#include <unistd.h>
int	main(void)
{
	int tab[] = {};
	char a;
	int i;
	i = 0;
	while (i < 9)
	{
		tab[i] = i;
		a = tab[i] + '0';
		write(1, &a, 1);
		i++ ;
	}
	ft_rev_int_tab(tab, 9);
	write(1, "\n", 1);
	i = 0;
	while (i < 8)
	{
		a = tab[i] + '0';
		write(1, &a, 1);
		i++ ;
	}
	return (0);
}
*/
