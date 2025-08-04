/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:22:22 by vilabard          #+#    #+#             */
/*   Updated: 2025/07/15 15:22:25 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				wanted_pos;
	int				moves;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*
typedef struct s_sdata
{
	struct s_stack	stack_a;
	struct s_stack	stack_b;
	size_t			size_a;
	size_t			size_b;

}	t_sdata;
*/

// ruled_action
void	swap(t_stack **stack, char *str);
void	push(t_stack **stack_to, t_stack **stack_from, char *str);
void	rotate(t_stack **stack, char *str);
void	r_rotate(t_stack **stack, char *str);

// stack_1
t_stack	*ft_stack_new(int value, int wanted_pos);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_addback(t_stack **stack, t_stack *new);
void	ft_stack_delone(t_stack *stack);
void	ft_stack_clear(t_stack **stack);

// stack_2
int		ft_stack_sorted(t_stack **stack);
int		ft_stack_rsorted(t_stack **stack);

// sort_big
int		ft_rotations(t_stack **stack_a, int len, int wanted);
int		ft_rotate_to_push(t_stack **stack_a, t_stack **stack_b, int wanted, int reverse);
void	ft_sort_big(t_stack **stack_a, size_t len);

// sort_small
void	ft_sort_3a(t_stack **stack);
void	ft_rsort_3b(t_stack **stack);
void	ft_sort_stack_b(t_stack **stack_b, size_t len_b);
void	ft_sort_small(t_stack **stack_a, int len);

// main 
void	ft_sort_stack(t_stack **stack_a, size_t len);
void	ft_stack_print(t_stack **stack, char *str);

// utilitarian
// sort

#endif
