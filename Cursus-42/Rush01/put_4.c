/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:55:47 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/27 17:02:04 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	display_map(int ***tab);

// Put 4 in front of constraint 1
void	ft_put_4_from1(int ***tab, int *sol)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i < 4)
			if (sol[i] == 1)
				tab[0][i][0] = 4;
		if (i >= 4 && i < 8)
			if (sol[i] == 1)
				tab[3][i - 4][0] = 4;
		if (i >= 8 && i < 12)
			if (sol[i] == 1)
				tab[i - 8][0][0] = 4;
		if (i >= 12 && i < 16)
			if (sol[i] == 1)
				tab[i - 12][3][0] = 4;
		i++;
	}
}

// Put 4 in third position if constraint are 3 and 2 
void	ft_put_4_from3_2(int ***tab, int *sol)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i < 4)
			if (sol[i] == 3 && sol[i + 4] == 2)
				tab[2][i][0] = 4;
		if (i >= 4 && i < 8)
			if (sol[i] == 3 && sol[i - 4] == 2)
				tab[1][i - 4][0] = 4;
		if (i >= 8 && i < 12)
			if (sol[i] == 3 && sol[i + 4] == 2)
				tab[i - 8][2][0] = 4;
		if (i >= 12 && i < 16)
			if (sol[i] == 3 && sol[i - 4] == 2)
				tab[i - 12][1][0] = 4;
		i++;
	}
}

// Put 1234 in front of constraint 4
void	ft_print_from4(int ***tab, int nbr_start, int row_or_col)
{
	int	j;

	j = 0;
	if (row_or_col > 0)
	{
		while (j < 4)
		{
			if (row_or_col == 1)
				tab[nbr_start][j][0] = j + 1;
			else
				tab[j][nbr_start][0] = j + 1;
			j++;
		}
	}
	else
	{
		while (j > -4)
		{
			if (row_or_col == -1)
				tab[nbr_start][3 + j][0] = (-j) + 1;
			else
				tab[3 + j][nbr_start][0] = (-j) + 1;
			j--;
		}
	}
}

// Find the constraint 4 to put 1234
void	ft_put_from4(int ***tab, int *sol)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i < 4)
			if (sol[i] == 4)
				ft_print_from4(tab, i, 2);
		if (i >= 4 && i < 8)
			if (sol[i] == 4)
				ft_print_from4(tab, i - 4, -2);
		if (i >= 8 && i < 12)
			if (sol[i] == 4)
				ft_print_from4(tab, i - 8, 1);
		if (i >= 12 && i < 16)
			if (sol[i] == 4)
				ft_print_from4(tab, i - 12, -1);
		i++;
	}
}

// Count how many time this specific number is on the grid
int	ft_count_int(int ***tab, int nb)
{
	int	row;
	int	col;
	int	result;

	row = 0;
	result = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tab[row][col][0] == nb)
			{
				result++;
			}
			col++;
		}
		row++;
	}
	return (result);
}
