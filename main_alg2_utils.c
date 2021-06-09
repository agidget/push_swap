#include "push_swap.h"

int	q_in_last(t_list **a)
{
	int		q;
	t_list	*t;

	q = 0;
	t = *a;
	while (t->index != 1)
	{
		q++;
		t = t->next;
	}
	return (q);
}

int	max_in_last_heap(t_list **a, int q)
{
	t_list	*t;
	int		max;

	t = *a;
	max = t->index;
	while (--q)
	{
		t = t->next;
		if (max < t->index)
			max = t->index;
	}
	return (max);
}

int	last_ind(t_list **a)
{
	t_list	*t;

	t = *a;
	while (t->next)
		t = t->next;
	return (t->index);
}

void	for_part_three(t_list **a, t_list **b, t_main *prime, t_list *t)
{
	if (t->index >= prime->mid)
	{
		op_pa(a, b);
		t->flag = prime->flag;
	}
	else if (t->index == prime->next)
	{
		op_pa(a, b);
		op_r(a, "ra\n");
		prime->next++;
	}
}

int	q_not_one_index(t_list **a)
{
	int		q;
	t_list	*t;

	q = 0;
	t = *a;
	if (t->flag != 0)
	{
		while (t->flag != 0)
		{
			q++;
			t = t->next;
		}
		return (q);
	}
	else
	{
		while (t->index != 1)
		{
			q++;
			t = t->next;
		}
		return (q);
	}
	return (q);
}
