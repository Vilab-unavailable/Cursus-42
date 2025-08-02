/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:49:37 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/05 09:51:05 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (c == (unsigned char)s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
