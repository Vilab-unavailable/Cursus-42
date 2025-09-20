#include "../include/minishell.h"

int	ft_env(t_list_str	*envp)
{
	t_list_str	*temp;

	temp = envp;
	while (temp)
	{
		printf("%n\n", temp->str);
		temp = temp->next
	}
	return (0);
}