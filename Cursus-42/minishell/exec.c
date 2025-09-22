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
/*
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
*/

void	set_in_out(t_data data, t_cmd cmd)
{
	while (cmd->redir_in)
	{
		cmd->fd[0] = ft_open(cmd, cmd->redir_in->path, cmd->redir_in->type);
		cmd->redir_in = cmd->redir_in->next;
	}
	if (cmd->fd[0] != -2)
		dup2(cmd->fd_in, STDIN_FILENO);
	else if (cmd->previous)
		dup2(cmd->previous->fd, STDIN_FILENO);

	while (cmd->redir_out)
	{
		cmd->fd_out = ft_open(cmd, cmd->redir_out->path, cmd->redir_out->type);
		cmd->redir_out = cmd->redir_out->next;
	}
	if (cmd->fd_out != -2)
		dup2(cmd->fd_out, STDOUT_FILENO);
	else if (cmd->next)
		dup2(cmd->next->fd_in, STDOUT_FILENO);

}

void	child(t_data data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1);
		printf("child fork failure\n");
	else
	{
		set_in_out(t_data data);
	}

}

int	exec_core(t_data *data)
{
	int	i;

	i = 0;
	
	while (cmd)
		{
			if (cmd->next)
				add_pipe(data);
			child(data, i++);
			cmd = cmd->next;
		}

	}
	
}
