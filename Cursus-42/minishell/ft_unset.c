#include "../include/minishell.h"

int	is_valid_id(char *str)
{
	int	i;

	i = 0;
	if (ft_isalpha(str[i]) || str[i] == '_')
	{
		i++
		while (str[i] && ft_isalnum(str[i]))
			i++;
		if (!str[i] || str[i] == '=')
			return (1);
	}
	return (0);
}

int	ft_unset(char **args)
{
	int	i;

	i = 0;
	if (!args || !args[0])
	{
		return (0, ft_env());
	}
	while (args[i])
	{
		if (is_valid_id(args[i]))
		{
			rm_envp(args[i]);
		}
		i++;
	}
	return (0);
}