/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:24:01 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/22 20:33:53 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_non_printable(char c)
{
	char	a;

	write(1, "\\", 1);
	if (c == 127)
		write(1, "7f", 2);
	else
	{
		a = c / 16 + '0';
		write(1, &a, 1);
		if (c % 16 < 10)
			a = (c % 16) + '0';
		else
			a = ((c % 16) - 10) + 'a';
		write(1, &a, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 31 || str[i] == 127)
		{
			ft_putchar_non_printable(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++ ;
	}
}
/*
void	ft_putstr(char *str)
{
	int	i;

	i = 0;	
	while (str[i])
	{
		write(1, &str[i], 1);
		i++ ;
	}
}

int	main(void)
{
	char str[] = "Coucou\ntu \tvas bien ?";

	ft_putstr(str);
	write(1, "\n", 1);
	ft_putstr_non_printable(str);
	return (0);
}
*/
