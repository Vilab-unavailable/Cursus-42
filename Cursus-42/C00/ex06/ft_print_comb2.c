/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:27:39 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/17 13:27:43 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_4char(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
}

void	ft_print_2int(int i, int p)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0' + (i / 10);
	b = '0' + (i % 10);
	c = '0' + (p / 10);
	d = '0' + (p % 10);
	ft_print_4char(a, b, c, d);
	if ((i != 98) || (p != 99))
	{
		write(1, ", ", 2);
	}
}	

void	ft_print_comb2(void)
{
	int	i;
	int	p;

	i = 0;
	while (i <= 98)
	{
		p = i + 1;
		while (p <= 99)
		{
			ft_print_2int(i, p);
			p++;
		}
		i++ ;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
