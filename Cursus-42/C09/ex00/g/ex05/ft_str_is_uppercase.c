/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:02:00 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/21 21:04:31 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
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
	
	check = ft_str_is_uppercase(str);
	if (check == 1)
		write(1, "str est majuscule ou vide", 29);
	else
		write(1, "str n est pas majuscule", 25);
}
*/
