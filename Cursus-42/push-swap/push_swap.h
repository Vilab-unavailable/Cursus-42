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
/*
typedef struct s_data
{
	long	*stack_a;
	long	*stack_b;
	size_t 	size_stack_a;
	size_t	size_stack_b;
}	t_data;
*/
typedef struct s_dl_list;
{
	long	value
	long	index
	struct s_stack_a *next
	struct s_stack_a *prev
}	t_dl_list;


typedef struct s_stack_a
{
	long	value
	long	index
	struct s_stack_a *next
	struct s_stack_a *prev
}	t_stack_a;

typedef struct s_stack_b
{
	long	value
	long	index
	struct s_stack_b *next
	struct s_stack_a *prev
}	t_stack_b;

#endif
