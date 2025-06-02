/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:44:15 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/28 11:44:17 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
Create a 3D box where the floor is our grid
whose height is filled with possibilities
*/
int	***make_tab(int size)
{
	int	i;
	int	j;
	int	k;
	int	***tab;

	tab = malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		tab[i] = malloc(size * sizeof(int));
		j = 0;
		while (j < size)
		{
			tab[i][j] = malloc((size + 1) * sizeof(int));
			k = 0;
			while (k <= size)
			{
				tab[i][j][k] = k;
				k++ ;
			}
			j++ ;
		}
		i++ ;
	}
	return (tab);
}

// Free the memory allocated to the 3D box
void	free_tab(int ***tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++ ;
	}
	free(tab);
}
