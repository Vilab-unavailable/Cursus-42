/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:17 by vilabard          #+#    #+#             */
/*   Updated: 2025/06/06 18:28:34 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	safe_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen(s1);
	res = ft_calloc(len + ft_strlen(s2) + 1, sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '\0';
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		res[len] = s2[i];
		len++ ;
		i++ ;
	}
	res[len] = '\0';
	return (safe_free(&s1), res);
}

char	*ft_read_to_buffer(int fd, char *buffer)
{
	char	*read_buffer;
	int		rbytes;

	read_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof (char));
	if (read_buffer == NULL)
		return (safe_free(&buffer), NULL);
	rbytes = read(fd, read_buffer, BUFFER_SIZE);
	if (rbytes < 0)
		return (safe_free(&read_buffer), safe_free(&buffer), NULL);
	while (rbytes > 0)
	{
		read_buffer[rbytes] = '\0';
		buffer = ft_strjoin_free(buffer, read_buffer);
		if (!buffer)
			return (safe_free(&read_buffer), NULL);
		if (ft_strchr(buffer, '\n') || rbytes < BUFFER_SIZE)
			return (safe_free(&read_buffer), buffer);
		rbytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	if (ft_strlen(buffer) > 0)
		return (safe_free(&read_buffer), buffer);
	return (safe_free(&read_buffer), safe_free(&buffer), NULL);
}

char	*ft_strdup_to(char *s, char c)
{
	size_t	i;
	char	*dup;
	int		stop;

	i = 0;
	stop = 0;
	dup = 0;
	dup = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!dup)
		return (NULL);
	else
	{
		while (s && s[i] && stop == 0)
		{
			dup[i] = (char)s[i];
			if (s[i] == c)
				stop = 1;
			i++;
		}
	}
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = "\0";
	if (fd <= -1 || BUFFER_SIZE == 0)
		return (NULL);
	if (buffer && ft_strchr(buffer, '\n'))
	{
		line = ft_strdup_to(buffer, '\n');
		buffer = ft_memmove(buffer, &buffer[ft_strlen(line)],
				ft_strlen(buffer) - ft_strlen(line) + 1);
		return (line);
	}
	buffer = ft_read_to_buffer(fd, buffer);
	if (!buffer)
		return (safe_free(&buffer), NULL);
	line = ft_strdup_to(buffer, '\n');
	if (!line)
		return (safe_free(&buffer), safe_free(&line), NULL);
	buffer = ft_memmove(buffer, &buffer[ft_strlen(line)],
			ft_strlen(buffer) - ft_strlen(line) + 1);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*doc;

	doc = "./get_next_line.c";
	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		doc = get_next_line(fd);
		if (!doc)
			break;
		printf("%s", doc);
		free(doc);
	}
	return (0);
}

