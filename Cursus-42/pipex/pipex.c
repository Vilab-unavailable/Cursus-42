/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:57:22 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/13 17:57:35 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len2;

	i = 0;
	len2 = ft_strlen(little);
	if (len2 == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && (big[i + j] == little[j])
			&& j + i < len)
		{
			j++ ;
			if (j == len2)
				return ((char *)&big[i]);
		}
		i++ ;
	}
	return (NULL);
}

void	ft_freetable(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

// extract from envp and return a table of possible paths
char	**ft_get_paths(char **envp)
{
	int		i;
	char	**t_path;

	t_path = NULL;
	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++ ;
	t_path = (char **)ft_split(envp[i], ':');
	return (t_path);
}

// find and test all paths in envp to return the first usable
char	*ft_which_path(char *cmd, char **envp)
{
	char	**t_path;
	char	*path;
	char	*full_path;
	int		i;
	int		j;

	t_path = ft_get_paths(envp);
	i = 0;
	while (t_path[i])
	{
		j = 0;
		while (t_path[i][j] && t_path[i][j] != '/')
			j++ ;
		path = ft_strjoin(t_path[i] + j, "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (access(full_path, F_OK | X_OK) == 0)
			return (ft_freetable(t_path), full_path);
		free(full_path);
		i++ ;
	}
	ft_freetable(t_path);
	return (0);
}

// commands are put into a char** to fit execve
void	ft_execute(char *str_cmd, char **envp)
{
	char	**t_cmd;
	char	*path;

	t_cmd = ft_split(str_cmd, ' ');
	path = ft_which_path(t_cmd[0], envp);
	if (path == NULL)
	{
		ft_putstr_fd(t_cmd[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_freetable(t_cmd);
		free(path);
		exit(1);
	}
	if (execve(path, t_cmd, envp) == -1)
	{
		perror("pipex");
		ft_freetable(t_cmd);
		free(path);
		exit(1);
	}
}
