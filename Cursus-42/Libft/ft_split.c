/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:45:58 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/21 16:46:00 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_sep(char test, char c)
{
	if (test == c)
		return (1);
	return (0);
}

char	*ft_strndup_3(const char *s, size_t n)
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

int	ft_count_word(char const *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (str[i] && is_sep(str[i], c) == 0)
		counter++ ;
	while (str[i])
	{
		if (str[i] && str[i - 1] && is_sep(str[i - 1], c) == 1
			&& is_sep(str[i], c) == 0)
			counter++ ;
		i++ ;
	}
	return (counter);
}

size_t	ft_len_to_sep(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], c) == 1)
			return (i);
		i++ ;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		n_word;
	char	**splitted;

	n_word = ft_count_word(s, c);
	splitted = ft_calloc((n_word + 1), sizeof(char *));
	if (splitted == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (i < n_word)
	{
		while (ft_len_to_sep(&s[j], c) == 0)
			j = j + 1;
		splitted[i] = ft_strndup_3(&s[j], ft_len_to_sep(&s[j], c));
		if (splitted[i] == 0)
			return (NULL);
		j = j + ft_len_to_sep(&s[j], c) + 1;
		i++ ;
	}
	splitted[i] = NULL;
	return (splitted);
}
/*
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++ ;
	}
}
		
int		main(void)
{
	char	*str = "je mange des  pommes";
	char	c = ' ';
	char 	**splitted;
	int	i;

	i = 0;
	write(1, "string to split :\n", 18);
	ft_putstr(str);
	write(1, "\nseparator used :\n", 18);
	write(1, &c, 1);
	write(1, "\nsplitted string :\n", 19);	
	splitted = ft_split(str, c);
	while (splitted[i] != 0)
	{
		ft_putstr(splitted[i++]);
		write(1, "\n", 1);
	}
	return (0);
}
*/
