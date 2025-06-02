/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:59:56 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/19 22:15:19 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}
/*
#include <string.h>
int	main(void)
{
	char str[3];
	char a;

	a = '0' + ft_strlen(&str[0]);
	write (1, &a, 1);
	a = '0' + strlen(&str[0]);
	write (1, &a, 1);
	return (0);
}
*/	
