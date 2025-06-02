/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:39:45 by vilabard          #+#    #+#             */
/*   Updated: 2025/06/02 19:37:37 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *s)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (ft_printstr("(null)"));
	while (s[i])
	{
		len += ft_printchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_type(va_list args, const char *str, int i, int len)
{
	if (!str[i])
		len = -1;
	else if (str[i] == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (str[i] == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (str[i] == 'p')
		len += ft_printptr(va_arg(args, void *));
	else if (str[i] == 'i' || str[i] == 'd')
		len += ft_printnbr(va_arg(args, int));
	else if (str[i] == 'u')
		len += ft_printunbr(va_arg(args, int));
	else if (str[i] == 'x')
		len += ft_printhexa(va_arg(args, unsigned int), 'a');
	else if (str[i] == 'X')
		len += ft_printhexa(va_arg(args, unsigned int), 'A');
	else if (str[i] == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;
	int			i;

	len = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i] && len >= 0)
	{
		if (str[i] == '%')
		{
			len = ft_type(args, str, i + 1, len);
			i++ ;
		}
		else
			len += ft_printchar(str[i]);
		i++ ;
	}
	va_end(args);
	return (len);
}

/*
#include <stdio.h>
int main()
{
    int a;
    int b;
    char *c;
    int i;
    unsigned int u;

    c = 0;
    i = -2147483648;
    u = 4294967295;
    a = ft_printf("%s%s", "copie", c);
    b = printf("%s%s", "vraie", c);
    
    ft_putnbr(a);
    write(1, "\n",1);
    ft_putnbr(b);
    write(1, "\n",1);
    return (0);
}
*/
