/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:15:07 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/07 18:15:09 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort the 5 unsorted cases
void	ft_sort_3a(t_stack **stack)
{
	int	top;
	int	second;
	int	third;

	top = (*stack)->wanted_pos;
	second = (*stack)->next->wanted_pos;
	third = (*stack)->next->next->wanted_pos;
	if (top < second && top < third && !(ft_stack_sorted(stack)))
	{
		r_rotate(stack, "rra\n");
		swap(stack, "sa\n");
	}
	else if (top < second && top > third)
		r_rotate(stack, "rra\n");
	else if (top > second && top < third)
		swap(stack, "sa\n");
	else if (top > second && top > third)
	{
		rotate(stack, "ra\n");
		if (!ft_stack_sorted(stack))
			swap(stack, "sa\n");
	}
}

// sort the 5 unsorted cases in reverse for b
void	ft_rsort_3b(t_stack **stack)
{
	int	top;
	int	second;
	int	third;

	top = (*stack)->wanted_pos;
	second = (*stack)->next->wanted_pos;
	third = (*stack)->next->next->wanted_pos;
	if (top < second && top < third)
	{
		rotate(stack, "rb\n");
		if (!ft_stack_rsorted(stack))
			swap(stack, "sb\n");
	}
	else if (top < second && top > third)
		swap(stack, "sb\n");
	else if (top > second && top < third)
		r_rotate(stack, "rrb\n");
	else if (top > second && top > third && !ft_stack_rsorted(stack))
	{
		swap(stack, "sb\n");
		if (!ft_stack_rsorted(stack))
			rotate(stack, "rb\n");
	}
}

void	ft_sort_stack_b(t_stack **stack_b, size_t len_b)
{
	if (len_b == 2 && !ft_stack_rsorted(stack_b))
		swap(stack_b, "sb\n");
	if (len_b == 3 && !ft_stack_rsorted(stack_b))
		return (ft_rsort_3b(stack_b));
}

void	ft_sort_small(t_stack **stack_a, int len)
{
	t_stack	*stack_b;
	size_t	len_b;

	stack_b = NULL;
	len_b = 0;
	while (len_b < len - 3)
	{
		if ((*stack_a)->wanted_pos <= len - 3)
		{
			push(&stack_b, stack_a, "pb\n");
			len_b++ ;
		}
		else
			rotate(stack_a, "ra\n");
	}
	ft_sort_stack_b(&stack_b, len_b);
	ft_sort_3a(stack_a);
	while (len_b > 0)
	{
		push(stack_a, &stack_b, "pa\n");
		len_b-- ;
	}
}
