/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:21:50 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/21 14:21:52 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_sep_set(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

char	*ft_strndup_2(const char *s, size_t n)
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

/*
ft_strtrim("-thingy_--_", "-_") must return "thingy"
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_sep_set(s1[start], set))
		start++;
	while (s1[end - 1] && is_sep_set(s1[end - 1], set))
		end--;
	if (start <= end)
	{
		return (ft_strndup_2(&s1[start], end - start));
	}
	else
	{
		return (ft_strndup_2(&s1[start], 0));
	}
}
