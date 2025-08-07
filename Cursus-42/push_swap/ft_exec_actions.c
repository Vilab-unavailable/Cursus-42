/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:22:01 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/07 18:22:03 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// execute the determined numbers of actions
void	ft_exec_rot_a(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	while (data->wrot_a > 0)
	{
		rotate(stack_a, "ra\n");
		data->wrot_a-- ;
	}
	while (data->wrot_a < 0)
	{
		r_rotate(stack_a, "rra\n");
		data->wrot_a++ ;
	}
}

void	ft_exec_rot_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	while (data->wrot_b > 0)
	{
		rotate(stack_b, "rb\n");
		data->wrot_b-- ;
	}
	while (data->wrot_b < 0)
	{
		r_rotate(stack_b, "rrb\n");
		data->wrot_b++ ;
	}
}

void	ft_exec_rot_both(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	while (data->wrot_both > 0)
	{
		rotate(stack_a, NULL);
		rotate(stack_b, "rr\n");
		data->wrot_both-- ;
	}
	while (data->wrot_both < 0)
	{
		r_rotate(stack_a, NULL);
		r_rotate(stack_b, "rrr\n");
		data->wrot_both++ ;
	}
}
