#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_cmd			//data for executing a single cmd
{
	char			**cmd_tab;	//tab de cmd + params only
	char			**args;		
	int				fd_in;
	int				fd_out;
	struct	s_cmd	*prev;
	struct	s_cmd	*next;
}					t_cmd;


typedef struct s_data
{
	t_cmd		*cmd;

	char		**envp;       // ou t_list
	int			pipefd[2];
	int			n_pipe;			// number of pipes
	int			env_shown;       // bool : cmd must only work once
	int			exit_status;



}				t_data




#endif