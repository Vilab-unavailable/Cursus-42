/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:23:32 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/28 16:23:28 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_tab_dup_2(int ***tab, int row, int i, int j);

// Check if a number is more than once in a line
int	check_tab_dup(int ***tab)
{
	int	col;
	int	row;
	int	i;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			i = 0;
			while (i < 4)
			{
				if (check_tab_dup_2(tab, row, col, i) == 1)
					return (0);
				i++;
			}
			row++;
		}
		col++;
	}
	return (1);
}

// Check whether the constraint are followed from right to left
int	check_row1(int ***tab, int *sol)
{
	int	i;
	int	counter;
	int	max;
	int	base;

	base = 0;
	while (base < 4)
	{
		max = tab[base][0][0];
		i = 1;
		counter = 1;
		while (i < 4)
		{
			if (tab[base][i][0] > max)
			{
				counter++;
				max = tab[base][i][0];
			}
			i++;
		}
		if (counter != sol[8 + base])
			return (0);
		base++;
	}
	return (1);
}

// Check whether the constraint are followed from left to right
int	check_row2(int ***tab, int *sol)
{
	int	i;
	int	counter;
	int	max;
	int	base;

	base = 0;
	while (base < 4)
	{
		max = tab[base][3][0];
		i = 3;
		counter = 1;
		while (i >= 0)
		{
			if (tab[base][i][0] > max)
			{
				counter++;
				max = tab[base][i][0];
			}
			i--;
		}
		if (counter != sol[12 + base])
			return (0);
		base++;
	}
	return (1);
}

// Check whether the constraint are followed from up to low
int	check_col1(int ***tab, int *sol)
{
	int	i;
	int	counter;
	int	max;
	int	base;

	base = 0;
	while (base < 4)
	{
		max = tab[0][base][0];
		i = 1;
		counter = 1;
		while (i < 4)
		{
			if (tab[i][base][0] > max)
			{
				counter++;
				max = tab[i][base][0];
			}
			i++;
		}
		if (counter != sol[base])
			return (0);
		base++;
	}
	return (1);
}

// Check whether the constraint are followed from low to up
int	check_col2(int ***tab, int *sol)
{
	int	i;
	int	counter;
	int	max;
	int	base;

	base = 0;
	while (base < 4)
	{
		max = tab[3][base][0];
		i = 3;
		counter = 1;
		while (i >= 0)
		{
			if (tab[i][base][0] > max)
			{
				counter++;
				max = tab[i][base][0];
			}
			i--;
		}
		if (counter != sol[4 + base])
			return (0);
		base++;
	}
	return (1);
}
