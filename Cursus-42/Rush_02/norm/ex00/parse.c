/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:58:28 by pmenard           #+#    #+#             */
/*   Updated: 2024/08/04 12:26:26 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strcat_dup(char *src);
int		error(int e, char *result);

char	*ft_read(char *dict_name, char *result)
{
	int		fd;
	char	buf[9999];
	int		nb_read;
	char	*dict;

	dict = NULL;
	fd = open(dict_name, O_RDONLY);
	if (fd == -1)
		return (dict + error(2, result));
	nb_read = -1;
	nb_read = read(fd, buf, 9998);
	if (nb_read == -1)
		return (dict + error(2, result));
	buf[nb_read] = '\0';
	dict = ft_strcat_dup(buf);
	if (dict == NULL)
		return (dict + error(2, result));
	close(fd);
	return (dict);
}
