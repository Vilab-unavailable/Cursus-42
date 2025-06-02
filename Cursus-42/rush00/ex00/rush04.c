/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibonnot <mibonnot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:28:58 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/21 15:29:13 by mibonnot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_draw04(int c, int l, int x, int y)
{			
	if (l == 1 && c == 1)
		ft_putchar('A');
	else if (l == 1 && c == x)
		ft_putchar('C');
	else if (l == y && c == x)
		ft_putchar('A');
	else if (l == y && c == 1)
		ft_putchar('C');
	else if (l == 1 || l == y)
		ft_putchar('B');
	else if (c == 1 || c == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
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
				ft_draw04(c, l, x, y);
				c++;
			}
			ft_putchar('\n');
			l++;
		}
	}
}
