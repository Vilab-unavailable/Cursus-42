/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:52:58 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/22 21:06:04 by vilabard         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i] && i < n)
	{
		dest[len] = src[i];
		len++ ;
		i++ ;
	}
	dest[len] = '\0';
	return (dest);
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
	char src[] = "Fonctionne mal";
	char dest[] = "la Fonction ";
	char src2[] = "Fonctionne super bien";
	char dest2[] = "\nla Fonction ";

	ft_putstr(ft_strncat(dest, src, 10));
	ft_putstr(ft_strncat(dest2, src2, 30));
	return (0);
}
*/
