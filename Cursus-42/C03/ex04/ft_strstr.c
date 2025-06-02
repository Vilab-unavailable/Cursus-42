/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:50:45 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/24 13:15:56 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(to_find);
	if (len == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && to_find[j] && (str[i + j] == to_find[j]))
		{
			j++ ;
			if (j == len)
				return (&str[i]);
		}
		i++ ;
	}
	return (NULL);
}
/*
#include<unistd.h>

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
	char str[] = "Cette fonction ne fonctionne fonctionnelement";
	char str2[] = "abba";

	ft_putstr(ft_strstr(str, str2));
	return (0);
}
*/
