/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:59:33 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/04 19:37:01 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		is_nbr(char c);
int		is_nbr_digit(char c);
int		count_zero(char *dict, int index);
char	*ft_dup_line(char *src);
char	*ft_strcat(char *dest, char *src);
void	error(int e, char *result);

void	ft_to_res(char *result, char *dict)
{
	int		i;
	char	*temp;

	i = 0;
	while (dict[i] != '\n')
	{
		while (is_nbr(dict[i]) || dict[i] <= 32 || dict[i] == 127
			|| dict[i] == ':')
			i++;
		temp = ft_dup_line(&dict[i]);
		ft_strcat(result, temp);
		free(temp);
		return ;
		i++;
	}
}

void	ft_print_0(int n_0, char *result, char *dict)
{
	int	i;
	int	j;

	i = 0;
	if (n_0 < 3)
		return ;
	while (dict[i])
	{
		if (dict[i] == '1' && is_nbr(dict[i - 1]) == 0)
		{
			j = 1;
			while (dict[i + j] == '0')
			{
				j++ ;
				if (j == n_0 + 1 && is_nbr(dict[i + j]) == 0)
				{
					ft_to_res(result, &dict[i + j]);
					return ;
				}
			}
		}
		i++;
	}
	return (error(2, result));
}
