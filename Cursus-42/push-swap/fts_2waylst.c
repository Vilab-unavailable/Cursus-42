t_dl_list	*ft_dl_lstnew(void *content)
{
	t_dl_list	*new;

	new = malloc(sizeof(t_dl_list));
	if (!(new))
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_dl_lstadd_front(t_dl_list **lst, t_list *new)
{
	t_dl_list	*temp;

	if (lst && new)
	{
		new->next = *lst;
		temp = *lst;
		temp->prev = new;
		*lst = new;
	}
}

void	ft_dl_lstdelone(t_dl_list *lst)
{
	if (!lst)
		return;
	if (lst->next)
		lst->next->prev = lst->prev;
	if (lst->prev)
		lst->prev->next = lst->next;
	free(lst)
}
	
void	ft_dl_lsrclear(t_list **lst, void (*del)(void *))
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
		ft_dl_lstdelone(todel, del);
	}
	*lst = NULL;
}
