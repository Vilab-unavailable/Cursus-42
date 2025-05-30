/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:39:45 by vilabard          #+#    #+#             */
/*   Updated: 2024/12/21 15:39:48 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *)
{
	size_t	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		len += ft_printchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_type(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (c == 's')
		len = ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		
	else if (c == 'd')
	else if (c == 'i')
	else if (c == 'u')
	else if (c == 'x')
	else if (c == 'X')
	else if (c == '%')
	return (len);
}
		


int	ft_printf(const char *str, ...)
{
	va_list		args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_type(args, str[i + 1]);
			i++ ;
		}
		else
			len += ft_printchar(str[i]);
		i++ ;
	}
	va_end(args);
	return (len);
}
int main()
{
    ft_putnbr_fd(ft_printf("BBB%s", "copie"), 1);
    write(1, "\n",1);
    ft_putnbr_fd(printf("A%s", "vrai"), 1);
    return (0);
}		
