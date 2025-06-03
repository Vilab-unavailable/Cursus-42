
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;

	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero((void *)alloc, nmemb * size);
	return ((void *)alloc);
}

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

char  *core(int fd, const char *buffer)
{
  char  *line;
  char  *read_buffer;
  int  rbytes;
  // seek /n inside of buffer, if yes dupplicate and return to next /n or end
  if (!buffer 
  
}
char  *get_next_line(int fd);
{
  const char  *buffer;
  char  *line;
  char  *

main()
{


  get_next_line

  if (fd < -1 OU BUFFER_SIZE == 0)
    return (NULL)
  
}
