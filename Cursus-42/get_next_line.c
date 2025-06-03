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

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;

	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero((void *)alloc, nmemb * size);
	return ((void *)alloc);
}

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

char	*ft_strndup(const char *s, size_t n)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = ft_strndup(&s[start], len);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ts;

	ts = (char *)s;
	i = 0;
	while (i < n)
	{
		ts[i] = 0;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	size_t	len2;
	char	*res;

	i = 0;
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = ft_calloc(len + len2 + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[len] = s2[i];
		len++ ;
		i++ ;
	}
	res[len] = '\0';
	return (res);
}
/*
char *read_buffer of size BUFFERSIZE holding temporarily what is read

const char *buffer of updated size to seek line inside of it, get joined by buffer, is reduced when Line is extracted

char *line hold the returned complete line 

fd is from open() ans is -1 if there is an issue, can be 0 ?

read() send back the number of bytes read
*/

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

char	*core(int fd, const char *buffer)
{
	char	*line;
	char	*read_buffer;

  

	
  // seek /n inside of buffer, if yes dupplicate and return to next /n or end
	if (
  
}

char	*ft_strdupto(const char *s, char c)
{
	size_t	i;
	char	*dup;
	int		stop;

	i = 0;
	stop = 0;
	dup = ft_calloc((n + 1), sizeof(char));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (s[i] && stop == 0)
		{
			dup[i] = (char)s[i];
			if (s[i] == '\n')
				stop = 1;
			i++;
		}
	}
	return (dup);
}
	
char	*get_next_line(int fd)
{
	const char	*buffer;
	char		*line;
	int			rbytes;
	int			next_pos;

	if (fd <= -1 OU BUFFER_SIZE == 0)
		return (NULL)
	if (buffer[0] && ft_strchr(buffer, '\n'))
	{
		line = ft_strdupto(buffer, '\n');
		buffer = ft_cut(buffer);
		return (line);
	}
		
		
      
int	main()
{
	int	fd;
	int	i

	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 1;
	while (i > 0)
	{
		i = printf("%s", get_next_line(fd));
	}
	return (0);
}
