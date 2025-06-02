/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:42:21 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/04 23:15:57 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		error(int e, char *result);
void	print_digit(char *nbr, char *dict, char *result);
void	print_teens(char *nbr, char *dict, char *result);
void	print_ty(char *nbr, char *dict, char *result);
void	print_hd(char *dict, char *result);
void	print_big(char *dict, int index, char *result);
void	ft_print_0(int n_0, char *result, char *dict);
void	ft_to_res(char *result, char *dict);
/*
 which take the string nbr ("   \n  +-+-+-+-000000012asD")
  and send the index of 1
*/

int	ft_skip(char *nbr, char *result)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
		if (nbr[i++] == '-')
			sign = -sign;
	if (sign < 0)
	{
		error(-1, result);
		return (-1);
	}
	while (nbr[i] == '0')
		i++;
	if (nbr[i] < '1' || nbr[i] > '9')
		i--;
	return (i);
}

int	ft_cut_nbr3(char *nbr, int len, char *result, char *dict)
{
	int	i;

	i = 0;
	while ((len - i) > 0 && (len - i) % 3 == 0)
	{
		if (nbr[i] != '0' || nbr[i + 1] != '0' || nbr[i + 2] != '0')
		{
			if (nbr[i] != '0')
			{
				print_digit(&nbr[i], dict, result);
				print_hd(dict, result);
			}
			if (nbr[i + 1] == '1')
				print_teens(&nbr[i + 1], dict, result);
			else
				print_ty(&nbr[i + 1], dict, result);
			ft_print_0((len - i - 3), result, dict);
		}
		i += 3;
	}
	return (0);
}

int	ft_cut_nbr2(char *nbr, int len, char *result, char *dict)
{
	int	i;

	i = 0;
	if (len % 3 == 2)
	{
		if (nbr[i] == '1')
			print_teens(nbr, dict, result);
		else
			print_ty(nbr, dict, result);
		i += 2;
		ft_print_0((len - i), result, dict);
		ft_cut_nbr3(&nbr[i], len - i, result, dict);
	}
	else
		ft_cut_nbr3(nbr, len, result, dict);
	return (0);
}	

/*
 which take the string nbr ("1234asD") and ask for the printing
 of "1" "1000" "200" "30" "4"
*/
int	ft_cut_nbr(char *nbr, char *result, char *dict)
{
	int	len;
	int	i;

	len = 0;
	while (nbr[len] >= '0' && nbr[len] <= '9')
		len++ ;
	if (len == 0)
		return (-1);
	i = 0;
	if (len % 3 == 1)
	{
		print_digit(nbr, dict, result);
		i += 1;
		ft_print_0((len - i), result, dict);
		ft_cut_nbr3(&nbr[i], len - i, result, dict);
	}
	ft_cut_nbr2(nbr, len, result, dict);
	return (0 * result[0]);
}
