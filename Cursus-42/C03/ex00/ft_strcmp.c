/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:38:00 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/22 19:46:07 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	while (s1[i] || s2[i])
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			return (diff);
		i++ ;
	}
	return (diff);
}
/*
#include <unistd.h>

int	main(void)
{
	char *s1 = "";
	char *s2 = "";

	if (ft_strcmp(s1, s2) == 0)
		write(1, "s1 et s2 sont egales\n", 20);
	if (ft_strcmp(s1, s2) < 0)
		write(1, "s1 est plus petite\n", 20);
	if (ft_strcmp(s1, s2) > 0)
		write(1, "s2 est plus petite\n", 20);
	return (0);
}
*/
