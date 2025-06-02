/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:45:15 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/21 20:45:18 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
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
	
	check = ft_str_is_lowercase(str);
	if (check == 1)
		write(1, "str est minuscule ou vide", 29);
	else
		write(1, "str n est pas minuscule", 25);
}
*/
