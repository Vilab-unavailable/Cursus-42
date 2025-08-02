/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:43:03 by vilabard          #+#    #+#             */
/*   Updated: 2024/11/07 14:43:05 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;

	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero((void *)alloc, nmemb * size);
	return ((void *)alloc);
}
