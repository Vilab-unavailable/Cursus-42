#include "../include/minishell.h"

int	ft_open(t_cmd cmd, char *path, int	type)
{
	int		fd;

	fd = 0;
	if (type == 1)
		fd = open(path, O_RDONLY, 0777);
	else if (type == 2)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (type == 3)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		if (opendir(path))			// or use stat() or perror  ?
			printf("%s: %s :%s\n", cmd_tab[0], path, "Is a directory\n");
		else
			printf("%s: %s :%s\n", cmd_tab[0], path, "No such file or directory\n");
	}
	return (fd);
}