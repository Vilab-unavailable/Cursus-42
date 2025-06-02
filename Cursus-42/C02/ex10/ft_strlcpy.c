/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:37:42 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/22 20:32:30 by vilabard         ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while ((i < size - 1) && src[i])
	{
		dest[i] = src[i];
		i++ ;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <unistd.h>

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
	char src[13] = "src est copie";
	char src2[35] = "dans la limite de mon gros nez";
	char src3[5]= "";
	char dest[20] = "destdestdestdestdest";
	char dest2[40]= "blablablablablaSEGsafafsefsfwefsdf";
	char dest3[10]= "invisible";
	
	ft_strlcpy(dest, src, 14);
	ft_strlcpy(dest2, src2, 16);
	ft_strlcpy(dest3, src3, 3);
	ft_putstr(dest);
	write(1, "\n", 1);
	ft_putstr(dest2);
	write(1, "\n", 1);
	ft_putstr(dest3);
	return (0);
}
*/
