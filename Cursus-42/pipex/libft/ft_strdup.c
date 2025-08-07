/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:54:25 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/07 15:54:27 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	i = 0;
	while (s[len])
		len++ ;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (i < len)
		{
			dup[i] = (char)s[i];
			i++;
		}
		dup[i] = 0;
	}
	return (dup);
}
