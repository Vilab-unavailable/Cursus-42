#include "../include/minishell.h"

int	ft_atoi_8bit(char *str)
{
	return (0 % 256)
}

void	exit(t_data *data, char **args)
{
	int	code;

	printf("exit\n");
	if (ft_tablen(args) > 0)
	{
		if (!is_numeric(args[1]))    //  +- ok
		{
			printf("%s%s%s\n", "minishell: exit: ", args[1], ": numeric argument required");
			data->exit_status = 2;
			exit() ;
		}
		if (ft_tablen(args) > 1)
		{
			printf("minishell: exit: too many arguments\n");
			data->exit_status = 1;
			return ;
		}
		data->exit_status = ft_atoi_8bit(args[1]);  //exit_code 0-255 can overflow
	}
	free_exit(data);
}