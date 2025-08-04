#include "push_swap.h"

int	ft_rotations(t_stack **stack_a, int len, int wanted)
{
	t_stack	*temp;
	int		rotations;
	int 	r_rotations;

	temp = *stack_a;
	rotations = 0;
	r_rotations = 1;
	while (temp->wanted_pos && temp->wanted_pos != wanted)
	{
		temp = temp->next;
		rotations++ ;
	}
	r_rotations = len - rotations;
	if (rotations <= r_rotations)
		return (rotations);
	else
		return (r_rotations * (-1));
}

// rotate the stack until it push the wanted element, may push the next element if on the way
int	ft_rotate_to_push(t_stack **stack_a, t_stack **stack_b, int wanted, int reverse)
{
	int	pushes;

	pushes = 0;
	while ((*stack_a)->wanted_pos != wanted)
	{
		if ((*stack_a)->wanted_pos == wanted + 1)
		{
			push(stack_b, stack_a, "pb\n");
			pushes++ ;
		}
		if (reverse == 0)
			rotate(stack_a, "ra\n");
		else
			r_rotate(stack_a, "rra\n");
	}
	push(stack_b, stack_a, "pb\n");
	pushes++ ;
	return (pushes);
}

void	ft_sort_big(t_stack **stack_a, size_t len)
{
	t_stack	*stack_b;
	int		wanted;
	int		rotations;
	int		pushes;

	stack_b = NULL;
	wanted = 1;
	pushes = 0;
	while (len > 3)
	{
		wanted += pushes;
		rotations = ft_rotations(stack_a, len, wanted);
		if (rotations > 0)
			pushes = ft_rotate_to_push(stack_a, &stack_b, wanted, 0);
		else
			pushes = ft_rotate_to_push(stack_a, &stack_b, wanted, 1);
		if (pushes == 2)
			swap(&stack_b, "sb\n");
		len -= pushes;
	}
	ft_sort_stack(stack_a, len);
	while (stack_b)
	{
		push(stack_a, &stack_b, "pa\n");
	}
}
