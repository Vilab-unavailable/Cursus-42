ee/* ************************************************************************** */
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
#include <stdarg.h>

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *s)
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


void	ft_putnbr_fd(int n, int fd)
{
	char	c;

    if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		c = '0' + (n % 10);
		n = n / 10;
		if (n != 0)
			ft_putnbr_fd(n, fd);
		write(1, &c, 1);
	}
}

int	ft_putptr(unsigned long long nb)
{
	char	c;

	if (nb % 16 <= 9)
		c = '0' + (nb % 16);
	else
		c = 'a' + (nb % 16);
	nb = nb / 16;
	if (nb != 0)
		ft_putptr(nb);
	ft_printchar(c);
}

int	ft_hexalen(unsigned long long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while ((n / 16 != 0) || (n % 16 != 0))
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_printptr(void *ptr)
{
    if (ptr == 0)
        return (ft_printstr("(nil)"));
	ft_printstr("0x");
	ft_putptr((unsigned long long) ptr);
	return (2 + ft_hexalen((unsigned long long) ptr));
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
        len = ft_printptr(va_arg(args, void *));
//	else if (c == 'd')
//	else if (c == 'i')
//	else if (c == 'u')
//	else if (c == 'x')
//	else if (c == 'X')
//	else if (c == '%')
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
    int a;
    int b;
    char *c;

    c = 0;
    a = ft_printf("B%s%p", "copie", c);
    b = printf("A%s%p", "vraie", c );
    
    ft_putnbr_fd(a, 1);
    write(1, "\n",1);
    ft_putnbr_fd(b, 1);
    return (0);
}
