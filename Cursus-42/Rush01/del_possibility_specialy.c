/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_possibility_specialy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:10:07 by jguaglio          #+#    #+#             */
/*   Updated: 2024/07/28 15:41:55 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Remove obvious impossibilities from left to right
void	del_possibility_special_row1(int ***tab, int *sol, int i)
{
	while (i < 4)
	{
		if (sol[8 + i] == 3 && sol [12 + i] == 1)
		{
			tab[i][0][3] = 0;
			tab[i][1][2] = 0;
		}
		if (sol[8 + i] == 3 && sol [12 + i] == 2)
		{
			tab[i][0][3] = 0;
			tab[i][1][1] = 0;
		}
		if (sol[8 + i] == 2 && sol [12 + i] == 2 && tab[i][1][0] == 4)
		{
			tab[i][2][3] = 0;
			tab[i][3][1] = 0;
		}
		if (sol[8 + i] == 2 && sol [12 + i] == 1)
			tab[i][0][0] = 3;
		i++;
	}
}

// Remove obvious impossibilities from right to left
void	del_possibility_special_row2(int ***tab, int *sol, int i)
{
	while (i < 4)
	{
		if (sol[8 + i] == 1 && sol [12 + i] == 3)
		{
			tab[i][3][3] = 0;
			tab[i][2][2] = 0;
		}
		if (sol[8 + i] == 2 && sol [12 + i] == 3)
		{
			tab[i][1][3] = 0;
			tab[i][2][1] = 0;
		}
		if (sol[8 + i] == 2 && sol [12 + i] == 2 && tab[i][2][0] == 4)
		{
			tab[i][1][3] = 0;
			tab[i][0][1] = 0;
		}
		if (sol[8 + i] == 1 && sol [12 + i] == 2)
			tab[i][3][0] = 3;
		i++;
	}
}

// Remove obvious impossibilities from up to low
void	del_possibility_special_col1(int ***tab, int *sol, int i)
{
	while (i < 4)
	{
		if (sol[i] == 3 && sol [4 + i] == 1)
		{
			tab[0][i][3] = 0;
			tab[1][i][2] = 0;
		}
		if (sol[i] == 3 && sol [4 + i] == 2)
		{
			tab[0][i][3] = 0;
			tab[1][i][1] = 0;
		}
		if (sol[i] == 2 && sol [4 + i] == 2 && tab[1][i][0] == 4)
		{
			tab[2][i][3] = 0;
			tab[3][i][1] = 0;
		}
		if (sol[i] == 2 && sol [4 + i] == 1)
			tab[0][i][0] = 3;
		i++;
	}
}

// Remove obvious impossibilities from low to up
void	del_possibility_special_col2(int ***tab, int *sol, int i)
{
	while (i < 4)
	{
		if (sol[i] == 1 && sol [4 + i] == 3)
		{
			tab[3][i][3] = 0;
			tab[2][i][2] = 0;
		}
		if (sol[i] == 2 && sol [4 + i] == 3)
		{
			tab[3][i][3] = 0;
			tab[2][i][1] = 0;
		}
		if (sol[i] == 2 && sol [4 + i] == 2 && tab[2][i][0] == 4)
		{
			tab[1][i][3] = 0;
			tab[0][i][1] = 0;
		}
		if (sol[i] == 1 && sol [4 + i] == 2)
			tab[3][i][0] = 3;
		i++;
	}
}

// Remove obvious impossibilities
void	del_possibility_special(int ***tab, int *sol)
{
	del_possibility_special_row1(tab, sol, 0);
	del_possibility_special_row2(tab, sol, 0);
	del_possibility_special_col1(tab, sol, 0);
	del_possibility_special_col2(tab, sol, 0);
}
