/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:04:34 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/21 17:23:33 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++ ;
	}
	return (1);
}
/*
#include <unistd.h>
int	main(void)
{
	char str[] = "782627682671757572";
	int	check;
	
	check = ft_str_is_numeric(str);
	if (check == 1)
		write(1, "str est numerique ou vide", 28);
	else
		write(1, "str n est pas numerique", 25);
}
*/
