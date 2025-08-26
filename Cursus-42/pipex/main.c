/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:49:09 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/13 17:57:48 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// do the command inputting from infile and outputting to outfile
void	ft_child(char **av, char **envp, int *pipefd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(av[1]);
		exit(1);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(pipefd[0]);
	ft_execute(av[2], envp);
}

// do the command after being set to write to outfile, and read from infile
void	ft_parent(char **av, char **envp, int *pipefd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(av[4]);
		exit(1);
	}
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
	int		pipefd[2];
	pid_t	pid;

	if (ac != 5)
		ft_putstr_fd("input : ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
	else
	{
		if (pipe(pipefd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			ft_child(av, envp, pipefd);
		waitpid(pid, NULL, 0);
		ft_parent(av, envp, pipefd);
	}
	return (0);
}
