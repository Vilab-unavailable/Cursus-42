/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:03:23 by vilabard          #+#    #+#             */
/*   Updated: 2025/08/07 18:03:26 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_sorted(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return (0);
	temp = *stack;
	while (temp)
	{
		if (temp->next == NULL)
			return (1);
		if (temp->value >= temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_stack_rsorted(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return (0);
	temp = *stack;
	while (temp)
	{
		if (temp->next == NULL)
			return (1);
		if (temp->value <= temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
