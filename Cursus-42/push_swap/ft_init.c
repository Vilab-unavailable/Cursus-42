/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:55:47 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/07 17:55:52 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_data	*ft_init_data(t_data *data, size_t len)
{
	data->len_a = len;
	data->len_b = 0;
	data->len_max = len;
	data->rot_a = 0;
	data->rot_b = 0;
	data->rot_both = 0;
	data->wrot_a = 0;
	data->wrot_b = 0;
	data->wrot_both = 0;
	data->min_move = 0;
	data->wanted = 0;
	return (data);
}
