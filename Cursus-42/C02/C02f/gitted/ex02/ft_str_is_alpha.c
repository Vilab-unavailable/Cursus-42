/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:53:22 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/21 17:03:55 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a')
			|| str[i] > 'z')
			return (0);
		i++ ;
	}
	return (1);
}
/*
#include <unistd.h>
int	main(void)
{
	char str[] = "alphnabet";
	int	check;
	
	check = ft_str_is_alpha(str);
	if (check == 1)
		write(1, "str est alpha ou vide", 22);
	else
		write(1, "str n est pas alpha", 25);
}
*/
