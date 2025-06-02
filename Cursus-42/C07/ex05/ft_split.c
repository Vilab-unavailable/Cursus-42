/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:18:03 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/02 22:38:23 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (str[i] && is_sep(str[i], charset) == 0)
		counter++ ;
	while (str[i])
	{
		if (str[i] && str[i - 1] && is_sep(str[i - 1], charset) == 1
			&& is_sep(str[i], charset) == 0)
			counter++ ;
		i++ ;
	}
	return (counter);
}

int	ft_len_to_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 1)
			return (i);
		i++ ;
	}
	return (i);
}

char	*ft_strndup(char *src, int n)
{
	int		len;
	char	*dup;
	int		i;

	len = 0;
	while (src[len])
		len++ ;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		*dup = 0;
	i = 0;
	while (i < n && src[i])
	{
		dup[i] = src[i];
		i++ ;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		n_word;
	char	**splitted;

	n_word = ft_count_word(str, charset);
	splitted = malloc((n_word + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < n_word)
	{
		while (ft_len_to_sep(&str[j], charset) == 0)
			j = j + 1;
		splitted[i] = ft_strndup(&str[j], ft_len_to_sep(&str[j], charset));
		j = j + ft_len_to_sep(&str[j], charset) + 1;
		i++ ;
	}
	splitted[i] = malloc(1 * sizeof(char));
	splitted[i] = 0;
	return (splitted);
}

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
	char	*str = 0;
	char	*charset = " ";
	char 	**splitted;
	int	i;

	i = 0;
	write(1, "string to split :\n", 18);
	ft_putstr(str);
	write(1, "\nseparator used :\n", 18);
	ft_putstr(charset);
	write(1, "\nsplitted string :\n", 19);	
	splitted = ft_split(str, charset);
	while (splitted[i] != 0)
	{
		ft_putstr(splitted[i++]);
		write(1, "\n", 1);
	}
	return (0);
}

