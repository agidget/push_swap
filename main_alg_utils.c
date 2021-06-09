#include "push_swap.h"

void	init_flags(t_list *a)
{
	while (a)
	{
		a->flag = 0;
		a = a->next;
	}
}

int	min_in_list(t_list **a)
{
	t_list	*t;
	int		min;

	t = *a;
	min = t->index;
	while (t->next)
	{
		t = t->next;
		if (min > t->index)
			min = t->index;
	}
	return (min);
}

int	max_in_list(t_list **a)
{
	t_list	*t;
	int		max;

	t = *a;
	max = t->index;
	while (t->next)
	{
		t = t->next;
		if (max < t->index)
			max = t->index;
	}
	return (max);
}
