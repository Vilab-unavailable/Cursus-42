/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:57:56 by pmenard           #+#    #+#             */
/*   Updated: 2024/08/04 23:16:24 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
int		is_nbr(char c);
int		is_nbr_digit(char c);
int		count_zero(char *dict, int index);
char	*ft_dup_line(char *src);
char	*ft_strcat(char *dest, char *src);
void	ft_to_res(char *result, char *dict);
void	error(int e, char *result);

void	print_digit(char *nbr, char *dict, char *result)
{
	int	i;

	i = 0;
	while (dict[i] != '\0' && nbr[0] != '0')
	{
		while (dict[i] != nbr[0])
			i++;
		if (is_nbr(dict[i - 1]) == 0
			&& is_nbr(dict[i + 1]) == 0)
		{
			ft_to_res(result, &dict[i]);
			return ;
		}
		i++;
	}
	error(2, result);
}

void	print_teens(char *nbr, char *dict, char *result)
{
	int	i;

	i = 0;
	while (dict[i++] != '\0')
	{
		if (dict[i] == nbr[1])
		{
			if ((dict[i - 1] == '1' && is_nbr(dict[i - 2]) == 0)
				&& (is_nbr(dict[i]) == 1) && is_nbr(dict[i + 1]) == 0)
			{
				ft_to_res(result, &dict[i]);
				return ;
			}
		}
	}
	error(2, result);
}

void	print_ty(char *nbr, char *dict, char *result)
{
	int	i;

	i = 0;
	while (dict[i++] != '\0')
	{
		if ((dict[i] == nbr[0] && is_nbr(dict[i - 1]) == 0)
			&& is_nbr(dict[i + 1]) == 1 && is_nbr(dict[i + 2]) == 0)
		{
			while (!(dict[i] >= 'A' && dict[i] <= 'Z')
				&& !(dict[i] >= 'a' && dict[i] <= 'z'))
				i++;
			ft_to_res(result, &dict[i]);
			if (nbr[1] >= '1' && nbr[1] <= '9')
			{
				print_digit(&nbr[1], dict, result);
			}
			return ;
		}
	}
	error(2, result);
}

void	print_hd(char *dict, char *result)
{
	int	i;
	int	stop_loop;

	i = 0;
	stop_loop = 0;
	while (dict[i++] != '\0' && stop_loop == 0)
	{
		if ((dict[i] == '1' && is_nbr(dict[i - 1]) == 0)
			&& is_nbr(dict[i + 2]) == 1 && is_nbr(dict[i + 3]) == 0
			&& count_zero(dict, i) == 1)
		{
			ft_to_res(result, &dict[i]);
			return ;
		}
	}
	error(2, result);
}
