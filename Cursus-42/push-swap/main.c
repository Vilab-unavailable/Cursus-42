/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:22:13 by vilabard          #+#    #+#             */
/*   Updated: 2025/07/15 15:22:16 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

long	ft_long_atoi(const char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++ ;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++ ;
	}
	return (res * sign);
}

size_t	ft_len_tchar(int ac, char **tchar)
{
	int		i;
	size_t	size;

	while (tchar[i])
	{
		i++;
		size++;
	}
	return (size);
}
int	ft_valid_input
{
			ft_putstr_fd("Error/n", 1)
}
int	ft_core(char **av, size_t size)
{
	t_data	*stack_data;
	int		i;
	int		error;
	long	nb;

	i = 0;
	error = 0;
	stack_data->stack_a = malloc(size * sizeof(int))
	if (stack_data->stack_a == NULL)
		return (-1);
	while (av[i])
	{
		stack_data->stack_a[i] = ft_long_atoi(av[i]);
		
		}
		
		
	
}

int	main(int ac, char **av)
{
	size_t	size;
	int		i;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		size = ft_len_tchar(ac, av));
	}
	else
	{
		av++ ;
		size = ac - 1;
	}
	ft_core(av, size);
	return (0);
}
	
