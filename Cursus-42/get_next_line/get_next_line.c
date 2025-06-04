/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:58:17 by vilabard          #+#    #+#             */
/*   Updated: 2025/06/03 17:58:20 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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
	if (s1)
		free(s1);
	return (res);
}
/*
char  *read_from_file(int fd)
{
  char  *read_buffer;

  read_buffer = ft_calloc((BUFF_SIZE + 1) * sizeof (char));
  if (read_buffer == NULL)
    return (NULL);
  if (read(fd, read_buffer, BUFF_SIZE) <= 0)
  {
    free(read_buffer);
    return(NULL);
  }
  return (read_buffer);
}
*/

char	*ft_read_to_buffer(int fd, char *buffer)
{
	char	*read_buffer;
	int		rbytes;

	read_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof (char));
	if (read_buffer == NULL)
		return (NULL);
	rbytes = read(fd, read_buffer, BUFFER_SIZE);
	while (rbytes > 0)
	{
		buffer = ft_strjoin_free(buffer, read_buffer);
		if (!buffer)
		{
			free(read_buffer);
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
		{
			free(read_buffer);
			return (buffer);
		}
		rbytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	free(read_buffer);
	return (NULL);
}

char	*ft_strdup_to(char *s, char c)
{
	size_t	i;
	char	*dup;
	int		stop;

	i = 0;
	stop = 0;
	dup = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (s[i] && stop == 0)
		{
			dup[i] = (char)s[i];
			if (s[i] == c)
				stop = 1;
			i++;
		}
	}
	return (dup);
}

char	*core(char *buffer, char *line)
{
	line = ft_strdup_to(buffer, '\n');
	if (ft_strchr(line, '\n'))
		buffer = ft_memmove(buffer, &buffer[ft_strlen(line)],
				ft_strlen(buffer) - ft_strlen(line) + 1);
	else
		free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static int	first;
	char		*line;

	line = "\0";
	first = 1;
	if (fd <= -1 || BUFFER_SIZE == 0)
		return (NULL);
	if (first == 0 && ft_strchr(buffer, '\n'))
	{
		line = ft_strdup_to(buffer, '\n');
		buffer = ft_memmove(buffer, &buffer[ft_strlen(line)],
				ft_strlen(buffer) - ft_strlen(line) + 1);
		return (line);
	}
	buffer = ft_read_to_buffer(fd, buffer);
	first = 0;
	if (buffer)
	{
		line = core(buffer, line);
		return (line);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*doc;

	doc = "./doc";
	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 1;
	while (i > 0)
	{
		i = 0;
		doc = get_next_line(fd);
		if (doc != NULL)
		{
			printf("%s", "get_next_line is not NULL\n");
			i = printf("%s", doc);
			free(doc);
		}
	}
	return (0);
}*/
