/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:58:35 by pmenard           #+#    #+#             */
/*   Updated: 2024/08/04 22:49:01 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	error(int e, char *result)
{
	if (e == 0)
		write(1, "Error, argument(s) must be : (dictionnary name) number\n", 55);
	else if (e == 1)
		write(1, "Error\n", 6);
	else if (e == 2)
		write(1, "Dict Error\n", 11);
	result[0] = '1';
}
