/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:22:13 by vilabard          #+#    #+#             */
/*   Updated: 2025/07/29 14:50:36 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freetable(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

long long	ft_llong_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++ ;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++ ;
	}
	return (res * sign);
}

int	ft_input_is_numeric(char **tstr)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (tstr[j])
	{
		while (tstr[j] && tstr[j][i])
		{
			if (!((tstr[j][i] >= '0' && tstr[j][i] <= '9') && !(tstr[j][i] == '-' && i == 0)))
				return (0);
			i++ ;
		}
		j++ ;
	}
	return (1);
}


long long	*ft_input_to_list(char **av, size_t len)
{
	size_t		i;
	long long	*list;

	i = 0;
	list = ft_calloc(len, sizeof(long long));
	while (i < len)
	{
		list[i] = ft_llong_atoi(av[i]);
		i++ ;
	}
	return (list);
}

// check for doubles and out of int
int	ft_check_values(long long *list, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(list[len - 1] > -2147483648 && list[len - 1] < 2147483647))
		return (1);
	while (i < len - 1)
	{
		if (!(list[i] > -2147483648 && list[i] < 2147483647))
			return (1);
		j = i + 1;
		while(j < len)
		{
			if (list[j] == list[i])
				return (1);
			j++ ;
		}
		i++ ;
	}
	return (0);
}
/*
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
// return the number of line in the table, ie the len of the list of int
size_t	ft_len_tchar(char **tchar)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (tchar[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_dup_table(char **tab)
{
	size_t	len;
	size_t	i;
	char	**newtab;

	len = ft_len_tchar(tab);
	newtab = ft_calloc((len + 1), sizeof(char **));
	i = 0;
	while (i < len)
	{
		newtab[i] = ft_strdup(tab[i]);
		i++ ;
	}
	return (newtab);
}

int	*ft_wanted_pos(long long *list, size_t len)
{
	int	*list_pos;
	size_t	i;
	size_t	j;
	int	pos;

	i = 0;
	list_pos = ft_calloc(len, sizeof(int));
	while (i < len)
	{
		j = 0;
		pos = 1;
		while (j < len)
		{
			if (list[j] < list[i])
				pos++ ;
			j++ ;
		}
		list_pos[i] = pos;
		i++ ;
	}
	return (list_pos);
}

t_stack	*ft_init_stack(long long *list, int len)
{
	t_stack	*stack_a;
	int		*list_pos;
	int		i;

	list_pos = ft_wanted_pos(list, len);
	stack_a = ft_stack_new((int) list[0], list_pos[0]);
	if (stack_a == NULL)
		return (free(list), free(list_pos), NULL);
	i = 1;
	while (i < len)
	{
		ft_stack_addback(&stack_a, ft_stack_new((int) list[i], list_pos[i]));
		i++ ;
	}
	free(list);
	free(list_pos);
	return (stack_a);
}
//////////////////////////////////////////////////  test
//#include <stdio.h>
/*
void	ft_stack_print(t_stack **stack, char *str)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (temp)
	{
		printf("%d%s%d%s", temp->value, "\t", temp->wanted_pos, "\n");
		temp = temp->next;
	}
	printf("%s%s", str, "\n\n\n\n");
}
*/
void	ft_sort_stack(t_stack **stack_a, size_t len)
{
	if (len == 2 && !(ft_stack_sorted(stack_a)))
		swap(stack_a, "sa\n");
	if (len == 3 && !(ft_stack_sorted(stack_a)))
		return (ft_sort_3a(stack_a));
	else if (len <= 6 && !(ft_stack_sorted(stack_a)))
		return (ft_sort_small(stack_a, len));
	else
		ft_sort_big(stack_a, len);
	//ft_stack_print(&stack_a, "stack_a");////////////test
}

int	ft_core(long long *list, size_t len)
{
	t_stack		*stack_a;
//	char		*res;

	stack_a = ft_init_stack(list, len);
	//ft_stack_print(&stack_a, "stack_a");////////////test
	if (ft_stack_sorted(&stack_a))
		return (ft_stack_clear(&stack_a), len * 0);
	ft_sort_stack(&stack_a, len);
	//ft_stack_print(&stack_a, "stack_a");////////////test
	ft_stack_clear(&stack_a);
	return (0);
}

//convert the input into a list of longlong and check its validity
int	main(int ac, char **av)
{
	size_t		len;
	long long	*list;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		len = ft_len_tchar(av);
		if (len == 1)
			return (ft_freetable(av), 0);
	}
	else
	{
		av = ft_dup_table(&av[1]);
		len = ac - 1;
	}
	list = ft_input_to_list(av, len);
	if (!ft_input_is_numeric(av) || ft_check_values(list, len))
		return (ft_freetable(av), free(list), ft_putstr_fd("Error\n", 1), 0);
	ft_freetable(av);
	ft_core(list, len);
	return (0);
}
