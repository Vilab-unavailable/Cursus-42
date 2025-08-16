/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:39:52 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/05 15:39:54 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len2;

	i = 0;
	len2 = ft_strlen(little);
	if (len2 == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && (big[i + j] == little[j])
			&& j + i < len)
		{
			j++ ;
			if (j == len2)
				return ((char *)&big[i]);
		}
		i++ ;
	}
	return (NULL);
}
