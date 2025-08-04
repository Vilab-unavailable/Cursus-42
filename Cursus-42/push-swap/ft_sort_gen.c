
void	ft_sort_stack_b(t_stack **stack_b, size_t len_b)
{
	if (len_b == 2 && !ft_stack_rsorted(stack_b))
		swap(stack_b, "sb\n");
	if (len_b == 3 && !ft_stack_rsorted(stack_b))
		return (ft_rsort_3b(stack_b));
}
