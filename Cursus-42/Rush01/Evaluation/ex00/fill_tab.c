/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:46:33 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/28 20:26:25 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_int(int ***tab, int nb);

// Find the position of identical number on the grid
int	*ft_search_nb(int ***tab, int nb)
{
	int	*res;
	int	row;
	int	col;

	res = malloc(sizeof(int) * 4);
	row = 0;
	while (row < 4)
		res[row++] = -1;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tab[row][col][0] == nb)
				res[row] = col;
			col++;
		}
		row++;
	}
	return (res);
}

// Fill the grid with the fourth identical number
void	ft_fill_tab_int(int ***tab, int nb)
{
	int	*pt_res;
	int	row;
	int	col;
	int	i;

	i = 0;
	col = 1;
	if (ft_count_int(tab, nb) != 3)
		return ;
	pt_res = ft_search_nb(tab, nb);
	while (i < 4)
	{
		if (pt_res[i] == -1)
			row = i;
		if (col == pt_res[i])
		{
			col++;
			i = -1;
		}
		i++;
	}
	if (tab[row][col - 1][0] == 0 && tab[row][col - 1][nb] == nb)
		tab[row][col - 1][0] = nb;
	free(pt_res);
}

// Find the single 0 in line and return its position
int	ft_one_0(int ***tab, int row_or_col, int nb)
{
	int	position;
	int	i;

	position = -1;
	i = 0;
	while (i < 4)
	{
		if (tab[nb][i][0] == 0 && row_or_col == 1)
		{
			if (position != -1)
				return (-1);
			position = i;
		}
		if (tab[i][nb][0] == 0 && row_or_col == 2)
		{
			if (position != -1)
				return (-1);
			position = i;
		}
		i++;
	}
	return (position);
}

// Complete the last 0 in line by the unused number
void	ft_fill_tab_one_case(int ***tab)
{
	int	i;
	int	sum;

	i = 0;
	while (i < 4)
	{
		if (ft_one_0(tab, 1, i) != -1)
		{
			sum = tab[i][0][0] + tab[i][1][0] + tab[i][2][0]
				+ tab[i][3][0];
			tab[i][ft_one_0(tab, 1, i)][0] = 10 - sum;
		}
		if (ft_one_0(tab, 2, i) != -1)
		{
			sum = tab[0][i][0] + tab[1][i][0] + tab[2][i][0]
				+ tab[3][i][0];
			tab[ft_one_0(tab, 2, i)][i][0] = 10 - sum;
		}
		i++;
	}
}
