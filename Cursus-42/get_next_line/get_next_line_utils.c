/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:05:21 by vilabard          #+#    #+#             */
/*   Updated: 2025/06/04 19:05:23 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ts;

	ts = (char *)s;
	i = 0;
	while (i < n)
	{
		ts[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;

	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero((void *)alloc, nmemb * size);
	return ((void *)alloc);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	while (s[i])
	{
		if (c == (unsigned char)s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (c == (unsigned char)s[i])
		return ((char *)&s[i]);
	return (0);
}
