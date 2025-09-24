#include "../include/minishell.h"


int	go_home(void)
{
	char	str[PATH_MAX];
	char	cwd[PATH_MAX];

	str = get_env(something, "HOME");
	if (!str)
	{
		printf("minishell: cd: HOME not set\n");
		return (1);
	}
	getcwd(cwd, sizeof(cwd));
	return (0);
}

int	ft_cd(char **args)
{
	char	*str;

	str = NULL;
	if (!args || !args[0])
		return (go_home());
		

	else if (ft_len_tchar(args) > 1)
	{
		printf("minishell: cd: too many arguments\n");
		return (1);
	}
	if ()
}