/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:39:49 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/28 20:26:49 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* Check whether the inputted string is of the correct format 
and the problem solvable
*/
char	is_input_good(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if ((i % 2) == 0)
		{
			if (input[i] < '1' && input[i] > '4')
				return ('n');
			else if ((i >= 8 && i <= 14) || i >= 24)
			{
				if ((input[i] + input[i - 8] - 96 < 3)
					|| (input[i] + input[i - 8] - 96 > 5))
					return ('n');
			}
		}
		else if (i % 2 == 1)
			if (input[i] != ' ')
				return ('n');
		i++;
	}
	if (i != 31)
		return ('n');
	return ('y');
}

// Convert the inputted string into a list of integrer
int	*convert(char *input)
{
	int	i;
	int	*sol;

	i = 0;
	sol = malloc(15 * sizeof(int));
	while (input[i])
	{
		if (i % 2 == 0)
			sol[i / 2] = input[i] - '0';
		i++ ;
	}
	return (sol);
}
