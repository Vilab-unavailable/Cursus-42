void	swap(t_dl_list **t_dl_list)
{
	int	temp;
	int	temp_i;

	if (t_dl_list == NULL || *t_dl_list == NULL)
		return;
	temp = (*t_dl_list)->value;
	temp_i = (*t_dl_list)->index;
	(*t_dl_list)->value = (*t_dl_list)->next->value;
	(*t_dl_list)->index = (*t_dl_list)->next->index;
	(*t_dl_list)->next->value = temp;
	(*t_dl_list)->next->index = temp_i;
}

// put the first element of the second list at the top of the first
void	push(t_dl_list **list_to, t_dl_list **list_from)
{
	t_dl_list	*temp;

	if (list_from == NULL || *list_from == NULL)
		return ;
	temp = *list_from;
	*list_from = (*list_from)->next;
	if (*list_from)
		*list_from)->prev = NULL;
	if (*list_to == NULL)
	{
		*list_to = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *list_to;
		temp->next->prev = temp;
		*list_to = temp;
	}
}
void	rotate(t_dl_list **list)
{
	t_dl_list *temp;

	if (list == NULL || *list == NULL || (*list->next == NULL))
		return;
	temp = ft_lstlast(*list);
	temp->next = *list;
	*list = temp->next->next;
	(*list)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
}

void	r_rotate(t_dl_list **list)
{
	t_dl_list *temp;

	if (list == NULL || *list == NULL || (*list->next == NULL))
		return;
	temp = ft_lstlast(*list);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *list;
	temp->next->prev = temp;
	*list = temp;
}
