/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ruled_actions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:50:03 by vilabard          #+#    #+#             */
/*   Updated: 2025/07/29 14:50:09 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// swap first two elements
void	swap(t_stack **stack, char *str)
{
	t_stack	*temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	temp->prev = temp->next;
	temp->next = temp->prev->next;
	temp->prev->prev = NULL;
	temp->prev->next = temp;
	*stack = temp->prev;
	if (str)
		ft_putstr_fd(str, 1);
}

// put the first element of the second stack at the top of the first
void	push(t_stack **stack_to, t_stack **stack_from, char *str)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	temp = *stack_from;
	temp2 = (*stack_from)->next;
	if (temp2)
		temp2->prev = NULL;
	*stack_from = temp2;
	if (*stack_to == NULL)
	{
		*stack_to = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack_to;
		temp->next->prev = temp;
		*stack_to = temp;
	}
	if (str)
		ft_putstr_fd(str, 1);
}

// put the first element at the back, the second at the top
void	rotate(t_stack **stack, char *str)
{
	t_stack	*temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	temp = ft_stack_last(*stack);
	temp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
	if (str)
		ft_putstr_fd(str, 1);
}

//put the last element at the top, the first as the second
void	r_rotate(t_stack **stack, char *str)
{
	t_stack	*temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	temp = ft_stack_last(*stack);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	temp->next->prev = temp;
	*stack = temp;
	if (str)
		ft_putstr_fd(str, 1);
}
