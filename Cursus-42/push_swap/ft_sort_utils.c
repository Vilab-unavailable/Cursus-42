/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:19:20 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/07 18:19:23 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return the number of double rotations possible
int	ft_simult_rot(int rot_a, int rot_b)
{
	int	simult;

	if (rot_a * rot_b < 0)
		return (0);
	simult = 0;
	while (rot_a - simult < 0 && rot_b - simult < 0)
		simult-- ;
	while (rot_a - simult > 0 && rot_b - simult > 0)
		simult++ ;
	return (simult);
}

// return the shortest way to rotate
int	ft_direction_rot(int rot, int len)
{
	if (rot > len - rot)
		rot = -(len - rot);
	return (rot);
}

// return the shortest number of rotation to get wanted on top
int	ft_rot_tofind(t_stack **stack, t_data *data)
{
	t_stack	*temp;
	int		rotations;
	int		r_rotations;

	temp = *stack;
	rotations = 0;
	while (temp->wanted_pos && temp->wanted_pos != data->len_max - 3)
	{
		temp = temp->next;
		rotations++ ;
	}
	r_rotations = data->len_b - rotations;
	if (rotations <= r_rotations)
		return (rotations);
	else
		return (r_rotations * (-1));
}

// order stack_b, then push it all into stack_a
void	ft_reorder_push(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	data->wrot_b = ft_rot_tofind(stack_b, data);
	ft_exec_rot_b(stack_a, stack_b, data);
	while (data->len_b > 0)
	{
		push(stack_a, stack_b, "pa\n");
		data->len_b-- ;
	}
}
/*
// initialize stack_b for big_sort
t_data	*ft_ready_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int	n;
	ft_stack_print(stack_a, "stack_a");////////////test
	n = data->len_max;
	printf("%s%d%s", "len_max  ", n, "\n\n\n");
	while (data->len_b < 3)
	{
		if ((*stack_a)->wanted_pos < data->len_max - 3)
		{
			push(stack_b, stack_a, "pb\n");
			data->len_b++ ;
			data->len_a-- ;
		}
		rotate(stack_a, "ra\n");
	}
	ft_sort_stack_b(stack_b, data->len_b);
//	ft_stack_print(stack_b, "stack_b");////////////test
	return (data);
}
*/
