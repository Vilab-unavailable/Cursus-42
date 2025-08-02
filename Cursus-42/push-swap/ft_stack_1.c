/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:33:14 by vilabard          #+#    #+#             */
/*   Updated: 2025/07/29 18:33:16 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ft_stack_new(int value, int wanted_pos)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!(new))
		return (NULL);
	new->value = value;
	new->wanted_pos = wanted_pos;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	return (temp);
}

void	ft_stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (stack && *stack && new)
	{
		temp = ft_stack_last(*stack);
		temp->next = new;
		temp->next->prev = temp;
	}
}

void	ft_stack_delone(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->next)
		stack->next->prev = stack->prev;
	if (stack->prev)
		stack->prev->next = stack->next;
	free(stack);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*todel;

	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		todel = tmp;
		tmp = tmp->next;
		ft_stack_delone(todel);
	}
	*stack = NULL;
}
