#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_list	*ft_lstnew(int num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->num = num;
		new->next = NULL;
	}
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*old;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	old = *lst;
	while (old->next)
		old = old->next;
	new->next = NULL;
	old->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}
