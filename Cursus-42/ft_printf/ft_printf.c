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

size_t ft_count(const char *s)
{
	size_t	i;
	size_t	c;
	int		conved;

	i = 0;
	c = 0;
	conved = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			c++;
			i++;
		}
		else if (i > 0 && s[i - 1] != '%')
			i++;
		else if (i > 0 && s[i - 1] == '%')


int	ft_printf(const char *s, ...)
{
	va_list		args;
	va_start	( args , n );
	size_t		l;
	size_t		i;

	i = 0;
	if (ft_strlen(const char *s) % 2;

