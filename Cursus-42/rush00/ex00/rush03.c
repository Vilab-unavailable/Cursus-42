/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibonnot <mibonnot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:52:12 by tcheikh           #+#    #+#             */
/*   Updated: 2024/07/21 22:57:14 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	ft_draw03(int c, int l, int x, int y)
{
	if (l == 1 && (c == 1))
		ft_putchar('A');
	else if (l == 1 && (c == x))
		ft_putchar('C');
	else if (l == y && (c == 1))
		ft_putchar('A');
	else if (l == y && (c == x))
		ft_putchar('C');
	else if (l == 1 || l == y)
		ft_putchar('B');
	else if (c == 1 || c == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
	return (0);
}

void	rush(int x, int y)
{
	int	c;
	int	l;

	if (x <= 0 || y <= 0)
		write(1, "input error", 11);
	else
	{
		l = 1;
		while (l <= y)
		{
			c = 1;
			while (c <= x)
			{
				ft_draw03(c, l, x, y);
				c++;
			}
			ft_putchar('\n');
			l++;
		}
	}
}
/*
int	main(void)
{
	rush(20, 5);
	return (0);
}
*/
