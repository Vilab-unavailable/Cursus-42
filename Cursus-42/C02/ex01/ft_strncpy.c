/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:33:40 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/21 15:50:50 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++ ;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++ ;
	}
	return (dest);
}

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
/*
int	main(void)
{
	char src[] = "la fonction ne copie que n caracteres, et elle est debile";
	char src2[] = "la fonction copie n caracteres minimum";
	char src3[]= "";
	char dest[] = "cette fonction est bien penible       , et j aime manger";
	char dest2[]= "asjcfbrbjksygcfjydsagcfrqcrcaewr        et j aime manger";
	char dest3[]= "invisible";
	char *buff;
	char *buff2;
	char *buff3;
	
	buff = ft_strncpy(dest, src, 38);
	buff2 = ft_strncpy(dest2, src2, 31);
	buff3 = ft_strncpy(dest3, src3, 3);
	ft_putstr(dest);
	write(1, "\n", 1);
	ft_putstr(dest2);
	write(1, "\n", 1);
	ft_putstr(dest3);
	return (0);
}
*/
