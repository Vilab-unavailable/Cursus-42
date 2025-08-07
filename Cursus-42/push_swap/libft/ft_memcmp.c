/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:44:48 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/05 14:44:51 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	int				diff;
	char			*ts1;
	char			*ts2;

	i = 0;
	diff = 0;
	ts1 = (char *)s1;
	ts2 = (char *)s2;
	while (i < (int)n)
	{
		diff = (unsigned char)ts1[i] - (unsigned char)ts2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (diff);
}
