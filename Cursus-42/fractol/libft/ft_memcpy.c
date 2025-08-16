/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:49:33 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/04 17:09:21 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*tsrc;
	char	*tdest;

	if (!dest && !src)
		return (NULL);
	tsrc = (char *)src;
	tdest = (char *)dest;
	i = 0;
	while (n != 0 && i < (int)n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dest);
}
