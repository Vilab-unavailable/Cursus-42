#include "../include/minishell.h"

int	ft_is_numeric(char *v)
{
	int	i;

	i = 0;
	if (v[i] && (v[i] == '-' || v[i] == '+'))
		i++ ;
	while (v[i])
	{
		if (v[i] < '0' || v[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


void	exit(t_data *data, char **args)
{
	int	code;

	printf("exit\n");
	if (ft_tablen(args) > 0)
	{
		if (!is_numeric(&args[1]))    //  +- ok
		{
			printf("%s%s%s\n", "minishell: exit: ", args[1], ": numeric argument required");
			data->exit_status = 2;
			exit(2) ;
		}
		if (ft_tablen(args) > 1)
		{
			printf("minishell: exit: too many arguments\n");
			data->exit_status = 1;
			return ;
		}
		data->exit_status = ft_atoi(args[1]) % 256;  //exit_code 0-255 can overflow
		if (data->exit_status < 0)
			data->exit_status *= -1;
	}
	free_exit(data);
}