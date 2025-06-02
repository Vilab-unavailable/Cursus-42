/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:33:57 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/06 13:41:37 by vilabard         ###   ########.fr       */
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

int	ft_find_lens(char **strs, int size)
{
	int	len_strs;
	int	i;

	i = 0;
	len_strs = 0;
	while (i < size)
	{
		len_strs += ft_strlen(strs[i]);
		i++ ;
	}
	return (len_strs);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;

	i = 0;
	join = NULL;
	if (size == 0)
	{
		join = malloc(1 * sizeof(char));
		join[0] = '\0';
		return (join);
	}
	join = malloc(((size - 1) * ft_strlen(sep) + ft_find_lens(strs, size)
				+ 1) * sizeof(char));
	if (join == NULL)
		return (join);
	join[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(join, strs[i]);
		if (i++ < size - 1)
			ft_strcat(join, sep);
	}
	return (join);
}
/*
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++ ;
	}
}

int	main() //(int argc, char **argv)
{
	char *temp;
	char *str1;
	char *str2;
	char *strall[2];
	char *sep;
	
	str1 = "";
	str2 = "";
	sep = "-_-";
	strall[0] = str1;
	strall[1] = str2;
	//strall[0] = 0;
	temp = ft_strjoin(2, strall, sep);
	ft_putstr(temp);
	free(temp);
	return (0);
}
*/
