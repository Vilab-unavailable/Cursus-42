#include "../include/minishell.h"

int	is_option_n(char *str)
{
	int	i;

	i = 0;
	if (str && str[i++] == '-')
	{
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++ ;
		}
	}
	if (i > 2)
		return (1);
	return (0);
}

int	ft_echo(char **args)
{
	int	i;
	int	j;
	int	newline;

	i = 0;
	newline = 1;
	while (is_option_n(argvs[i]))
	{
		newline = 0;
		i++ ;
	}
	while (argvs[i])
	{
		printf("%s", argvs[i++]);
		if (argvs[i])
			printf(" ");
	}
	if (newline == 1)
		printf("\n");
	return (0);
}
