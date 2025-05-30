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

int	ft_printstr
		
int	ft_type(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		
	else if (c == 's')
	else if (c == 'p')
	else if (c == 'd')
	else if (c == 'i')
	else if (c == 'u')
	else if (c == 'x')
	else if (c == 'X')
	else if (c == '%')
		


int	ft_printf(const char *str, ...)
{
	va_list		args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s)
		return (-1);
	va_start(args, str);
	while (str[i] & len >= 0)
	{
		if (str[i] == '%')
		{
			len = ft_type(args, str[i + 1], len);
			i++ ;
		}
		else
			len += ft_printchar(str[i]);
		i++ ;
	}
	va_end(args);
	return (len);
}
		
			
