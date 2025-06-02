/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:23:32 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/28 20:23:02 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_tab_dup(int ***tab);

int	check_row1(int ***tab, int *sol);

int	check_row2(int ***tab, int *sol);

int	check_col1(int ***tab, int *sol);

int	check_col2(int ***tab, int *sol);

// call various checking functions for dupplicates and constraints requirements
int	check(int ***tab, int *sol)
{
	if (check_tab_dup(tab) == 0)
		return (0);
	else if (check_row1(tab, sol) == 0)
		return (0);
	else if (check_row2(tab, sol) == 0)
		return (0);
	else if (check_col1(tab, sol) == 0)
		return (0);
	else if (check_col2(tab, sol) == 0)
		return (0);
	return (1);
}

/*
second part of check_tab_dup which check if there are dupplicates
in lines and columns
*/
int	check_tab_dup_2(int ***tab, int row, int i, int j)
{
	if ((tab[row][i][0] == tab[row][j][0]
		|| tab[i][row][0] == tab[j][row][0]) && i != j
		&& tab[row][i][0] != 0 && tab[i][row][0] != 0)
		return (1);
	return (0);
}
