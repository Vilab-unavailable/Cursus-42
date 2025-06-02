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
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

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

    if (n == -2147483648)
		ft_printstr("-2147483648");
    else if (n < 0)
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

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	c;

	c = '0' + (n % 10);
	n = n / 10;
	if (n != 0)
		ft_putnbr_fd(n, fd);
	write(1, &c, 1);
}

int	ft_intlen(int n)
{
	size_t	len;

	len = 0;
    if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n *= -1;
		len++;
	}
	while ((n / 10 != 0) || (n % 10 != 0))
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_uintlen(unsigned int n)
{
	size_t	len;

	len = 0;
	while ((n / 10 != 0) || (n % 10 != 0))
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_printnbr(int n)
{
    ft_putnbr_fd(n, 1);
    return (ft_intlen(n));
}

int	ft_printunbr(int n)
{
    ft_putunbr_fd(n, 1);
    return (ft_uintlen(n));
}

int	ft_putullhexa(unsigned long long nb)
{
	char	c;

	if (nb % 16 <= 9)
		c = '0' + (nb % 16);
	else
		c = 'a' + (nb % 16) - 10;
	nb = nb / 16;
	if (nb != 0)
		ft_putullhexa(nb);
	ft_printchar(c);
}

int	ft_ullhexalen(unsigned long long n)
{
	int	len;

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
	ft_putullhexa((unsigned long long) ptr);
	return (2 + ft_ullhexalen((unsigned long long) ptr));
}

int	ft_puthexa(unsigned int nb)
{
	char	c;

	if (nb % 16 <= 9)
		c = '0' + (nb % 16);
	else
		c = 'a' + (nb % 16) - 10;
	nb = nb / 16;
	if (nb != 0)
		ft_puthexa(nb);
	ft_printchar(c);
}

int	ft_puthexabig(unsigned int nb)
{
	char	c;

	if (nb % 16 <= 9)
		c = '0' + (nb % 16);
	else
		c = 'A' + (nb % 16) - 10;
	nb = nb / 16;
	if (nb != 0)
		ft_puthexabig(nb);
	ft_printchar(c);
}


int	ft_hexalen(unsigned int n)
{
	int	len;

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

int ft_printhexa(unsigned int nb, char c)
{
    if (c == 'a')
        ft_puthexa(nb);
    else if (c == 'A')
        ft_puthexabig(nb);
    return (ft_hexalen(nb));
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
//	else if (str[i] == 'd')
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
	int		len;
	int		i;

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
int main()
{
    int a;
    int b;
    char *c;
    int i;
    unsigned int u;

    c = "this a sentence with an adress";
    i = -2147483648;
    u = 4294967295;
    a = ft_printf("B%sp%x", "copie", u);
    b = printf("A%sp%x", "vraie", u);
    
    ft_putnbr_fd(a, 1);
    write(1, "\n",1);
    ft_putnbr_fd(b, 1);
    write(1, "\n",1);
    ft_putnbr_fd(-2147483648, 1);
    return (0);
}
*/
