/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:46:43 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/24 13:16:38 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	diff = 0;
	while ((s1[i] || s2[i]) && i < n)
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
	char *s1 = "je mange des pommes";
	char *s2 = "je mange des poires";

	if (ft_strncmp(s1, s2, 5) == 0)
		write(1, "s1 et s2 sont egales a 5 char\n", 30);
	if (ft_strncmp(s1, s2, 20) < 0)
		write(1, "s1 est plus petite\n", 20);
	if (ft_strncmp(s1, s2, 20) > 0)
		write(1, "s2 est plus petite\n", 20);
	return (0);
}
*/
