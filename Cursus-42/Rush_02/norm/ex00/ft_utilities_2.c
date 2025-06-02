/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:52:43 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/04 18:06:41 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	is_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	count_zero(char *dict, int index)
{
	int	zeros;
	int	count;
	int	i;

	zeros = 0;
	count = 0;
	i = index + 1;
	while (is_nbr(dict[i]))
	{
		if (dict[i] == '0')
			zeros++;
		count++;
		i++;
	}
	if (zeros == count)
		return (1);
	else
		return (0);
}

char	*ft_strcat_dup(char *src)
{
	int		j;
	char	*dup;

	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dup == NULL)
		return (dup);
	j = 0;
	while (src[j])
	{
		dup[j] = src[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

char	*ft_dup_line(char *src)
{
	int		j;
	char	*dup;

	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dup == NULL)
		return (dup);
	j = 0;
	while (src[j] != '\n')
	{
		while (((src[j - 1] >= 9 && src[j - 1] <= 13) || src[j - 1] == 32)
			&& ((src[j] >= 9 && src[j] <= 13) || src[j] == 32))
			j++;
		dup[j] = src[j];
		j++;
	}
	dup[j] = ' ';
	dup[j + 1] = '\0';
	return (dup);
}
