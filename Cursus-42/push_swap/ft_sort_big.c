/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:04:06 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/07 18:04:09 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return the number of rot_b required to fit wanted in stack_b 
if wanted is the new min_b
*/
t_data	*ft_how_sort_min_b(t_stack **stack_b, t_data *data)
{
	t_stack	*temp_b;
	int		span;
	int		s_span;
	int		rot_b;

	temp_b = *stack_b;
	s_span = INT_MAX;
	rot_b = 0;
	while (temp_b)
	{
		span = data->wanted - temp_b->wanted_pos;
		if (span < 0 && s_span > ft_absolute(span))
		{
			s_span = ft_absolute(span);
			data->rot_b = ft_direction_rot(rot_b + 1, data->len_b);
		}
		temp_b = temp_b->next;
		rot_b++ ;
	}
	return (data);
}

// return the number of rot_b required to fit wanted in stack_b
t_data	*ft_how_sort_2(t_stack **stack_b, t_data *data)
{
	t_stack	*temp_b;
	int		span;
	int		s_span;
	int		rot_b;

	temp_b = *stack_b;
	s_span = INT_MAX;
	rot_b = 0;
	while (temp_b)
	{
		span = data->wanted - temp_b->wanted_pos;
		if (span > 0 && s_span > span)
		{
			s_span = span;
			data->rot_b = ft_direction_rot(rot_b, data->len_b);
		}
		temp_b = temp_b->next;
		rot_b++ ;
	}
	if (s_span == INT_MAX)
		return (ft_how_sort_min_b(stack_b, data));
	return (data);
}

t_data	*ft_save_data(t_data *data, int wanted, int moves)
{
	data->min_move = moves;
	data->wanted = wanted;
	data->wrot_a = data->rot_a;
	data->wrot_b = data->rot_b;
	data->wrot_both = data->rot_both;
	return (data);
}

// determines and returns how to sort the cheapest element via data
t_data	*ft_how_sort_1(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*temp_a;
	int		rot_a;
	int		moves;

	temp_a = *stack_a;
	rot_a = 0;
	data->min_move = INT_MAX;
	while (temp_a)
	{
		data->rot_a = ft_direction_rot(rot_a, data->len_a);
		data->wanted = temp_a->wanted_pos;
		ft_how_sort_2(stack_b, data);
		data->rot_both = ft_simult_rot(data->rot_a, data->rot_b);
		data->rot_a = data->rot_a - data->rot_both;
		data->rot_b = data->rot_b - data->rot_both;
		moves = 1 + ft_absolute(data->rot_a) + ft_absolute(data->rot_b)
			+ ft_absolute(data->rot_both);
		if (data->min_move > moves && temp_a->wanted_pos <= data->len_max - 3)
			ft_save_data(data, temp_a->wanted_pos, moves);
		temp_a = temp_a->next;
		rot_a++ ;
	}
	return (data);
}

// sort the element one by one after identifying the cheapest to sort
void	ft_sort_big(t_stack **stack_a, size_t len)
{
	t_stack	*stack_b;
	t_data	data;

	stack_b = NULL;
	ft_init_data(&data, len);
	while (data.len_a > 3)
	{
		if (data.len_b == 3)
			ft_sort_stack_b(&stack_b, data.len_b);
		ft_how_sort_1(stack_a, &stack_b, &data);
		ft_exec_rot_a(stack_a, &stack_b, &data);
		ft_exec_rot_b(stack_a, &stack_b, &data);
		ft_exec_rot_both(stack_a, &stack_b, &data);
		push(&stack_b, stack_a, "pb\n");
		data.len_b++ ;
		data.len_a-- ;
	}
	ft_sort_3a(stack_a);
	ft_reorder_push(stack_a, &stack_b, &data);
}
