/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:49:09 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/07 15:49:11 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



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
char	*ft_get_paths(char **envp)
{
	int		i;
	char	**t_path;

	t_path = NULL;
	while (ft_strnstr(envp[i], "PATH", 4) == 0);
		i++ ;
	t_path = ft_split(envp[i + 5], ':');
	return (t_path);	
}

// find and test all paths in envp to return the first usable
char	*ft_which_path(char *cmd, char **envp)
{
	char	**t_path;
	char	*path;
	char	*full_path;
	int		i;

	t_path = ft_split(ft_get_paths(envp), ';');
	i = 0;
	while (t_path[i])
	{
		path = ft_strjoin(t_path[i], "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);                    // free t_path ?
		free(full_path);
		i++ ;
	}
	ft_freetable(t_path);
	return (0);	
}

void	ft_execute(char *str_cmd, char **envp)
{
	char	**t_cmd;
	char	*path;

	t_cmd = ft_split(str_cmd, ' ');
	path = ft_which_path(t_cmd[0], envp);
	if (execve(path, t_cmd, envp) == -1)
	{
		ft_freetable(t_cmd);
		perror("command not found\n, 2");  // free path ?
	}
	// free path ?
	// free t_cmd ?
}
		

// do the command inputting from infile and outputting to outfile
void	ft_child(char **av, char **envp, int *pipefd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
		exit(-1);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(pipefd[0]);
	ft_execute(av[2], envp);
}

// do the command after being set to write to outfile, and read from infile
void	ft_parent(char **av, char **envp, int *pipefd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY| O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		exit(-1);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[1]);
	ft_execute(av[3], envp);
}

/*
Launches the two processes after checking the input
pipefd[1] is write, [0] is read
*/
int	main(int ac, char **av, char **envp)
{
//	t_pipex	pdata;
	int		pipefd[2];
	pid_t	pid;

	if (ac != 5)
		return (-1, ft_putstr_fd("accept arguments :
			./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2));
	else
	{
		if (pipe(pipefd) == -1)
			exit(-1);
		pid = fork();
		if (pid == -1)
			exit(-1);
		if (pid == 0)
			ft_child(av, envp, pipefd);
		waitpid(pid, NULL, 0);
		ft_parent(av, envp, pipefd);
	}
	return (0);
}
/* main()
{
	ft_init_pipex()
	ft_check_args()
	ft_parse_cmds()
	ft_parse_args()
	while (cmds)
		ft_exec()
	ft_cleanup()
}*/
