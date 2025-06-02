/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:33:04 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/22 11:20:46 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_what_is_char(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return ('A');
	}
	if (c >= '0' && c <= '9')
	{
		return ('1');
	}	
	else if (c >= 'a' && c <= 'z')
	{
		return ('a');
	}
	else
		return ('o');
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	upped;

	i = 0;
	upped = 'n';
	while (str[i])
	{
		if (ft_what_is_char(str[i]) == 'a' && upped == 'n')
		{
			str[i] = str[i] - 32;
			upped = 'y';
		}
		else if ((ft_what_is_char(str[i]) == 'A'
				|| ft_what_is_char(str[i]) == '1') && upped == 'n')
		{
			upped = 'y';
		}
		else if (ft_what_is_char(str[i]) == 'A' && upped == 'y')
			str[i] = str[i] + 32;
		else if (ft_what_is_char(str[i]) == 'o')
			upped = 'n';
		i++ ;
	}
	return (str);
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
	char *buff;

	char str[] = "salut, comMENT tu vas ? 42mots quarante-deux; cinquante+eT+un";
	ft_putstr(str);
	write(1, "\n", 1);
	buff = ft_strcapitalize(str);
	ft_putstr(buff);
	return (0);
}
*/	
