#include "push_swap.h"

int ft_stack_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = stack;
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