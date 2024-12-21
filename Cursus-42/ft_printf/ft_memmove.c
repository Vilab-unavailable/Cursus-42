/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:01:14 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/04 17:09:33 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tdest;
	char	*tsrc;
	size_t	i;

	i = 0;
	tdest = (char *)dest;
	tsrc = (char *)src;
	if (tsrc > tdest)
	{
		while (i < n)
		{
			tdest[i] = tsrc[i];
			i++;
		}
	}
	if (tsrc < tdest)
	{
		while (n > 0)
		{
			tdest[n - 1] = tsrc[n - 1];
			n--;
		}
	}
	return (dest);
}
