/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:28:51 by vilabard          #+#    #+#             */
/*   Updated: 2024/08/04 23:16:08 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	error(int e, char *result);
char	*ft_read(char *dict, char *result);
int		ft_skip(char *nbr);
int		ft_cut_nbr(char *nbr, char *result, char *dict);
void	ft_putstr(char *str);

int	core(char *dict, char *nbr, char *result)
{
	if (result[0] != '0')
	{
		free(dict);
		free(result);
		return (0);
	}
	ft_cut_nbr(&nbr[ft_skip(nbr)], result, dict);
	if (result[0] != '0')
	{
		free(dict);
		free(result);
		return (0);
	}
	ft_putstr(result);
	free(dict);
	free(result);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dict_name;
	char	*dict;
	char	*nbr;
	char	*result;

	dict_name = "./numbers.dict";
	result = NULL;
	result = malloc(9999 * sizeof(char));
	result[0] = '0';
	if (argc == 2)
		nbr = argv[1];
	else if (argc == 3)
	{
		dict_name = argv[1];
		nbr = argv[2];
	}
	else
	{
		error(1, result);
		return (1);
	}
	dict = ft_read(dict_name, result);
	core(dict, nbr, result);
	return (0);
}
