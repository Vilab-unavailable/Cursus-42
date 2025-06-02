/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:05:47 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/19 09:52:46 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
/*
#include<unistd.h>

int	main(void)
{
	int i;
	int*nbr;

	i = 0;
	nbr = &i;
	ft_ft(nbr);
	if (i == 42)
		write(1, "ma fonction fonctionne", 25);
	return (0);
}
*/
