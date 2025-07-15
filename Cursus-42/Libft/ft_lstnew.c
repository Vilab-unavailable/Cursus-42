/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilabard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:01:58 by vilabard          #+#    #+#             */
/*   Updated: 2025/07/15 16:02:00 by vilabard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list		*new;

	new = malloc(sizeof(t_list));
	if (!(new))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		i++;
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	return (tmp);
}

int	main(void)
{
	t_list	*list;
	t_list	*list0;
	t_list	*tmp;
	char	*string;

	string = "love apples";
	list = ft_lstnew(string);
	string = "I ";
	list0 = ft_lstnew(string);
	ft_lstadd_front(&list, list0);
	tmp = list;
	/*while (tmp)
	{
		printf("%s", (char *)tmp->content);
		tmp = tmp->next;
	}
	*/
	printf("%i", ft_lstsize(list));
	tmp = ft_lstlast(list);
	printf("%s", (char *)tmp->content);
	return (0);
}
