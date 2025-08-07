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
/*
//////////////////////////////////////////////////  test
#include <stdio.h>

void	ft_stack_print(t_stack **stack, char *str)////////////////////
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
//	if (ft_stack_sorted(&stack_a))////////////////////////
//		printf("%s", "    correctly sorted\n\n");//////////////////
//	ft_stack_print(&stack_a, "stack_a\n");////////////test
*/

int	*ft_wanted_pos(long long *list, size_t len)
{
	int		*list_pos;
	size_t	i;
	size_t	j;
	int		pos;

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

void	ft_sort_stack(t_stack **stack_a, size_t len)
{
	if (len == 2 && !(ft_stack_sorted(stack_a)))
		swap(stack_a, "sa\n");
	else if (len == 3 && !(ft_stack_sorted(stack_a)))
		return (ft_sort_3a(stack_a));
	else if (len <= 5 && !(ft_stack_sorted(stack_a)))
		return (ft_sort_small(stack_a, len));
	else if (len > 5 && !(ft_stack_sorted(stack_a)))
		ft_sort_big(stack_a, len);
}

int	ft_core(long long *list, size_t len)
{
	t_stack		*stack_a;

	stack_a = ft_init_stack(list, len);
	if (ft_stack_sorted(&stack_a))
		return (ft_stack_clear(&stack_a), len * 0);
	ft_sort_stack(&stack_a, len);
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
		if (len == 1 && ft_input_is_numeric(av))
			return (ft_freetable(av), 0);
	}
	else
	{
		av = ft_dup_table(&av[1]);
		len = ac - 1;
	}
	list = ft_input_to_list(av, len);
	if (!(ft_input_is_numeric(av) && !(ft_check_values(list, len))))
		return (ft_freetable(av), free(list), ft_putstr_fd("Error\n", 1), 0);
	ft_freetable(av);
	ft_core(list, len);
	return (0);
}
