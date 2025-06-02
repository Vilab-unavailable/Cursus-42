/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_possibility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:57:21 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/28 20:23:15 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Removes possibilities of supplicates
void	ft_del_possibility(int ***tab, int value, int row, int col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tab[row][i][value] = 0;
		tab[i][col][value] = 0;
		i++;
	}
}

// Find fixed case to prevent dupplicates
void	ft_find_del_possibility_rc(int ***tab)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (col < 4)
	{
		while (row < 4)
		{
			if (tab[row][col][0] != 0)
				ft_del_possibility(tab, tab[row][col][0], row, col);
			row++;
		}
		col++;
		row = 0;
	}
}

// Check the number of possibilities left and return the index if only one
int	find_3_0(int	*tab)
{
	int	unique_sol;
	int	i;

	i = 1;
	unique_sol = -1;
	while (i < 5)
	{
		if (tab[i] != 0)
		{
			if (unique_sol != -1)
				return (-1);
			unique_sol = i;
		}
		i++;
	}
	return (unique_sol);
}

// Put the only possibility as solution
void	set_unique_possibility(int ***tab)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (col < 4)
	{
		while (row < 4)
		{
			if (find_3_0(tab[row][col]) != -1 && tab[row][col][0] == 0)
				tab[row][col][0] = find_3_0(tab[row][col]);
			row++;
		}
		col++;
		row = 0;
	}
}
