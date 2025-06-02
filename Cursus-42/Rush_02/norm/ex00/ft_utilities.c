/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:58:32 by pmenard           #+#    #+#             */
/*   Updated: 2024/08/03 15:01:10 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i + 1])
	{
		write(1, &str[i], 1);
		i++ ;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len] = src[i];
		len++ ;
		i++ ;
	}
	dest[len] = '\0';
	return (dest);
}
