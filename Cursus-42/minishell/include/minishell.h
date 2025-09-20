#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

/* handle multiple in redirections and here_doc 
ex : <txt1 <txt2 cat <<stop <txt3
txt1 2 must be open(readonly) without error
std_in must be read until the line stop is found
txt3 must be open(readonly) without error and set as in
*/
typedef struct s_fd_in			
{
	int				fd_in;
	int				type_in;
	struct	s_cmd	*prev;
	struct	s_cmd	*next;
}					t_fd_in;

/* handle multiple out redirections 
ex :>txt1 echo thing >>txt2
txt1 must be open(trunc | creat) without error
txt2 must be open(appnd | creat) without error and set as out
*/
typedef struct s_fd_out			
{
	int				fd_out;
	int				type_out;
	struct	s_cmd	*prev;
	struct	s_cmd	*next;
}					t_fd_out;

typedef struct s_list_str		// to store envp
{
	char			*str;
	struct	s_cmd	*prev;
	struct	s_cmd	*next;
}					t_list;

typedef struct s_cmd			//data for executing a single cmd
{
	char			**cmd_tab;
	t_fd_in			fd_in;
	t_fd_out		fd_out;
	struct	s_cmd	*prev;
	struct	s_cmd	*next;
}					t_cmd;

typedef struct s_pipe		// to store envp
{
	int				*fd[2];
	struct	s_cmd	*prev;
	struct	s_cmd	*next;
}					t_pipe;


typedef struct s_data
{
	t_list_str	*envp;

	t_cmd		*cmd;

	t_pipe	pipefd;

	int			n_pipe;
	int			env_shown;       // bool : cmd must only work once
	int			exit_status;



}				t_data




#endif