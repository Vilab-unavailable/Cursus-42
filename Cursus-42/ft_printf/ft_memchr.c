/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:29:29 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/05 14:29:32 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ts;
	unsigned char	tc;

	ts = (unsigned char *)s;
	tc = (unsigned char)c;
	i = 0;
	while (i < (int)n)
	{
		if (tc == ts[i])
			return ((void *)&ts[i]);
		i++;
	}
	return (0);
}
