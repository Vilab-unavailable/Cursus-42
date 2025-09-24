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

int	ft_export(char **args)
{
	int	i;
	int	exit;

	i = 0;
	if (!args || !args[0])
	{
		return (0, ft_env());
	}
	while (args[i])
	{
		if (is_valid_id(args[i]))
		{
			add_envp(args[i]);
		}
		else
		{
			printf("%s%s%s\n", "minishell: export: ", args[i], ": wrong arg");
			exist = 1;
		}
		i++;
	}
	return (exit);
}