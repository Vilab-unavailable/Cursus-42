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
	t_list	*temp;

	if (lst && new)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	if (!lst)
		return (NULL);
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
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	return (tmp);
}

int	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lsr->content);
		free(lst);
	}
}

void	ft_lsrclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*todel;

	if (!lst)
		return (NULL);
	tmp = *lst;
	while (tmp)
	{
		todel = tmp;
		tmp = tmp->next;
		ft_lstdelone(todel, del);
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*res;

	if (!lst)
		return (NULL);
	tmp = 0
	res = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp)
		{
			ft_lstadd_back(&res, tmp);
			lst = lst->next;
		}
		else
			return (ft_lstclear(&res, del));
	}
	return (res);
	
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
