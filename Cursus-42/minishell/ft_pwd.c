#include "../include/minishell.h"

int	ft_pwd(void)
{
	char	*cwd[PATH_MAX];

	if (!getcwd(cwd, PATH_MAX))
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", cwd);
	return (0);
}