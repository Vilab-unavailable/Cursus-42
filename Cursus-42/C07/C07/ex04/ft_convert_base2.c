/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:33:02 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/07 22:11:29 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

int		ft_check_base(char *base);

int		ft_atoi_base(char *str, char *base);

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

void	ft_strrev_minus_minus(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == '-')
			i++ ;
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		i++ ;
		len-- ;
	}
}

void	ft_convert_nbr_base(int nbr, char *base, int len_base, char *result)
{
	int		i;

	i = 0;
	while (result[i])
		i++ ;
	if (nbr < 0)
	{
		result[i++] = '-';
		result[i++] = base[-(nbr % len_base)];
		ft_convert_nbr_base(-(nbr / len_base), base, len_base, &result[i]);
	}
	else if (nbr / len_base != 0)
	{
		result[i] = base[nbr % len_base];
		ft_convert_nbr_base((nbr / len_base), base, len_base, &result[i]);
	}
	else
		result[i] = base[nbr % len_base];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len_to;
	int		len_from;
	int		temp;
	char	result[64];

	temp = 0;
	while (temp < 63)
		result[temp++] = '\0';
	len_from = ft_check_base(base_from);
	len_to = ft_check_base(base_to);
	if (len_from < 2 || len_to < 2)
		return (0);
	temp = ft_atoi_base(nbr, base_from);
	ft_convert_nbr_base(temp, base_to, len_to, result);
	ft_strrev_minus_minus(result);
	return (ft_strdup(result));
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
	char *nbr;
	char *base1;
	char *base2;

	base1 = "0123456789";
	base2 = "01";
	
	nbr = "-123";
	ft_putstr(nbr);
	write(1, "test\n", 5);
	ft_putstr(ft_convert_base(nbr, base1, base2));
	write(1, "\n", 1);
	nbr = "0";
	ft_putstr(nbr);
	write(1, "test\n", 5);
	ft_putstr(ft_convert_base(nbr, base1, base2));
	write(1, "\n", 1);
	nbr = "-2147483648";
	ft_putstr(nbr);
	write(1, "test\n", 5);
	ft_putstr(ft_convert_base(nbr, base1, base2));
	return (0);
}
*/
