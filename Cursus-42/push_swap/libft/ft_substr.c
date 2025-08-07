/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:53:29 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/07 16:53:31 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = ft_calloc((n + 1), sizeof(char));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (i < n)
		{
			dup[i] = (char)s[i];
			i++;
		}
	}
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = ft_strndup(&s[start], len);
	return (res);
}
