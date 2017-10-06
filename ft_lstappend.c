t_list	*ft_lstappend(t_list *list, t_list *new)
{
	t_list	*cur;

	cur = list;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = new;
	return (list);
}
