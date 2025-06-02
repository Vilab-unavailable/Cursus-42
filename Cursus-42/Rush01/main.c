/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:17:51 by vilabard          #+#    #+#             */
/*   Updated: 2024/07/27 15:41:44 by dacarate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdlib.h>

void	ft_put_4_from1(int ***tab, int *sol);

void	ft_put_4_from3_2(int ***tab, int *sol);

void	ft_print_from4(int ***tab, int nbr_start, int row_or_col);

void	ft_put_from4(int ***tab, int *sol);

int		ft_count_int(int ***tab, int nb);

void	display_map(int ***tab);

int		check_if_zero(int ***tab);

int		*convert(char *input);

char	is_input_good(char *input);

void	del_possibility_special(int ***tab, int *sol);

void	ft_del_possibility(int ***tab, int value, int row, int col);

void	ft_find_del_possibility_rc(int ***tab);

void	set_unique_possibility(int ***tab);

int		find_3_0(int *tab);

int		error(int e);

int		check(int ***tab, int *sol);

void	ft_fill_tab_one_case(int ***tab);

void	ft_fill_tab_int(int ***tab, int nb);

int		***make_tab(int size);

void	free_tab(int ***tab, int size);

/*
Prevent the functions from competing with each other
and complee obvious lines
*/
void	verification(int ***tab)
{
	ft_find_del_possibility_rc(tab);
	ft_fill_tab_one_case(tab);
}

// Game loop
void	solve(int ***tab, int *sol)
{
	int	cnt;

	ft_put_4_from1(tab, sol);
	ft_put_4_from3_2(tab, sol);
	ft_put_from4(tab, sol);
	cnt = 0;
	while (cnt < 15 && check_if_zero(tab) == 0)
	{
		ft_fill_tab_int(tab, 4);
		ft_fill_tab_int(tab, 3);
		ft_fill_tab_int(tab, 2);
		ft_fill_tab_int(tab, 1);
		verification(tab);
		set_unique_possibility(tab);
		verification(tab);
		del_possibility_special(tab, sol);
		verification(tab);
		cnt++ ;
	}
}

// Make a true programm from this bundle of functions
int	main(int argc, char **argv)
{
	int	***tab;
	int	*sol;

	if (argc != 2 || is_input_good(argv[1]) == 'n')
		return (error(1));
	sol = convert(argv[1]);
	tab = make_tab(4);
	solve(tab, sol);
	if (check_if_zero(tab) == 1 && check(tab, sol) == 1)
		display_map(tab);
	else
		error(1);
	free_tab(tab, 4);
	free(sol);
	return (0);
}
