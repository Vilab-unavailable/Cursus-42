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

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				wanted_pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	size_t	len_a;
	size_t	len_b;
	size_t	len_max;
	int		rot_a;
	int		rot_b;
	int		rot_both;
	int		wrot_a;
	int		wrot_b;
	int		wrot_both;
	int		min_move;
	int		wanted;
}	t_data;

// init
long long	*ft_input_to_list(char **av, size_t len);
t_stack		*ft_init_stack(long long *list, int len);
t_data		*ft_init_data(t_data *data, size_t len);

// checks
int			ft_check_values(long long *list, size_t len);
int			ft_input_is_numeric(char **tstr);

// ruled_action
void		swap(t_stack **stack, char *str);
void		push(t_stack **stack_to, t_stack **stack_from, char *str);
void		rotate(t_stack **stack, char *str);
void		r_rotate(t_stack **stack, char *str);

// stack_1
t_stack		*ft_stack_new(int value, int wanted_pos);
t_stack		*ft_stack_last(t_stack **stack);
void		ft_stack_addback(t_stack **stack, t_stack *new);
void		ft_stack_delone(t_stack *stack);
void		ft_stack_clear(t_stack **stack);

// stack_2
int			ft_stack_sorted(t_stack **stack);
int			ft_stack_rsorted(t_stack **stack);

// sort_big
void		ft_sort_big(t_stack **stack_a, size_t len);

// sort_utils
int			ft_absolute(int nbr);
int			ft_simult_rot(int rot_a, int rot_b);
int			ft_direction_rot(int rot, int len);
int			ft_rot_tofind(t_stack **stack, t_data *data);
void		ft_reorder_push(t_stack **stack_a, t_stack **stack_b, t_data *data);

// exec_actions
void		ft_exec_rot_a(t_stack **stack_a, t_stack **stack_b, t_data *data);
void		ft_exec_rot_b(t_stack **stack_a, t_stack **stack_b, t_data *data);
void		ft_exec_rot_both(t_stack **stack_a, t_stack **stack_b,
				t_data *data);

// sort_small
void		ft_sort_3a(t_stack **stack);
void		ft_rsort_3b(t_stack **stack);
void		ft_sort_stack_b(t_stack **stack_b, size_t len_b);
void		ft_sort_small(t_stack **stack_a, int len);

// main 
void		ft_sort_stack(t_stack **stack_a, size_t len);
void		ft_stack_print(t_stack **stack, char *str);
int			*ft_wanted_pos(long long *list, size_t len);

// utilitarian
void		ft_freetable(char **tab);
int			ft_absolute(int nbr);
long long	ft_llong_atoi(const char *str);
size_t		ft_len_tchar(char **tchar);
char		**ft_dup_table(char **tab);

#endif
