/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:18:26 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/05 09:49:20 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
