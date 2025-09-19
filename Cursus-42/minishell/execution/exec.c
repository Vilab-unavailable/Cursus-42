#include "../include/minishell.h"

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

int	check_cmd(t_data data, char str_cmd)
{
	if 

}

// commands are put into a char** to fit execve
void	ft_exec_cmd(t_data *data, char *str_cmd, char **envp)
{
	char	**cmd_tab;
	char	*path;


	cmd_tab = ft_split(str_cmd, ' ');
	if (ft_strchr(cmd_tab[0], '/'))
		check_cmd(data, cmd_tab[0]);
	else
		path = ft_which_path(cmd_tab[0], envp);
	}
	if (path == NULL) 
	{
		ft_putstr_fd(cmd_tab[0], 2);                       //
		ft_putendl_fd(": command not found", 2);         //use perror ?
		data->exit_status = 127;
		ft_freetable(cmd_tab);
		free(path);
		exit(1);
	}
	if (execve(path, cmd_tab, envp) == -1)
	{
		perror("pipex");
		ft_freetable(cmd_tab);
		free(path);
		exit(1);
	}
}
void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	child(t_data data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1);
		printf("child fork failure\n");
	else if (pid == 0)
	{
		if (cmd->previous)
			dup2(fd_out of previous, STDIN_FILENO);
		if (cmd->next)
			dup2(fd_in of next, STDOUT_FILENO);
	}

}

int	exec_core(t_data *data)
{
	int	i;

	i = 0;
	make_pipe(data);
	if (data->n_pipe > 0)
	{
		while (i <= data->n_pipe)
		{
			child(data, i++);
			cmd = cmd->next;
		}

	}
	
}
