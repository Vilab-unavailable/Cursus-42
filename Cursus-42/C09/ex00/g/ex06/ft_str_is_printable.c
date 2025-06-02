/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:05:48 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/21 21:05:53 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 31 || str[i] == 127)
			return (0);
		i++ ;
	}
	return (1);
}
/*
#include <unistd.h>
int	main(void)
{
	char str[] = "QLPHQBET";
	int	check;
	
	check = ft_str_is_printable(str);
	if (check == 1)
		write(1, "str est imprimable ou vide", 29);
	else
		write(1, "str n est pas imprimable", 25);
}
*/
