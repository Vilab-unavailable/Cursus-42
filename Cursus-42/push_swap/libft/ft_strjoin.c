/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:13:20 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/21 12:13:23 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	size_t	len2;
	char	*res;

	i = 0;
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = ft_calloc(len + len2 + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[len] = s2[i];
		len++ ;
		i++ ;
	}
	res[len] = '\0';
	return (res);
}
