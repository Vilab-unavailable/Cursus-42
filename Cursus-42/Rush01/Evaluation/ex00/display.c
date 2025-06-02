/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:32:26 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/28 20:26:13 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	error(int e);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Display the floor of the 3D box, aka the grid
void	display_map(int ***tab)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			ft_putchar(tab[x][y][0] + '0');
			if (y < 3)
			{
				ft_putchar(' ');
			}
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

// Check if there are remaining 0 on the grid
int	check_if_zero(int ***tab)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tab[x][y][0] == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
