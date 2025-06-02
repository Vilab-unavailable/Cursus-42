/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:16:18 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/29 16:50:06 by vilabard         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++ ;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;

	len = ft_strlen(src);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		*dup = 0;
	else
		dup = ft_strcpy(dup, src);
	return (dup);
}
/*
#include <unistd.h>
#include <string.h>

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	while (s1[i] || s2[i])
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			return (diff);
		i++ ;
	}
	return (diff);
}

int	main(int argc, char **argv)
{
	char *buff;

	if (argc == 2)
	{
		buff = ft_strdup(argv[1]);
		if (ft_strcmp(buff, strdup(argv[1])) == 0)
			ft_putstr(buff);
	}
	return (0);
}
*/
