#include "push_swap.h"

void	sort_two(t_list **a)
{
	t_list	*t;

	t = *a;
	if (t->index > t->next->index)
		op_s(a, "sa\n");
}

void	sort_three(t_list **a)
{
	t_list	*t;

	t = *a;
	if ((t->index > t->next->index) && (t->index < t->next->next->index)
		&& (t->next->index < t->next->next->index))
		op_s(a, "sa\n");
	else if ((t->index > t->next->index) && (t->index > t->next->next->index)
		&& (t->next->index > t->next->next->index))
	{
		op_s(a, "sa\n");
		op_rr(a, "rra\n");
	}
	else if ((t->index > t->next->index) && (t->index > t->next->next->index)
		&& (t->next->index < t->next->next->index))
		op_r(a, "ra\n");
	else if ((t->index < t->next->index) && (t->index < t->next->next->index)
		&& (t->next->index > t->next->next->index))
	{
		op_s(a, "sa\n");
		op_r(a, "ra\n");
	}
	else if ((t->index < t->next->index) && (t->index > t->next->next->index)
		&& (t->next->index > t->next->next->index))
		op_rr(a, "rra\n");
}

void	sort_four(t_list **a, t_list **b)
{
	t_list	*t;
	int		min;

	t = *a;
	min = min_in_list(a);
	while (t)
	{
		if (t->index == min)
			break ;
		op_r(a, "ra\n");
		t = *a;
	}
	op_pb(a, b);
	sort_three(a);
	op_pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	t_list	*t;
	t_list	*t1;
	int		min;
	int		i;

	min = min_in_list(a);
	i = 2;
	while (i--)
	{
		t = *a;
		while (t)
		{
			if (t->index == min || t->index == min + 1)
				break ;
			op_r(a, "ra\n");
			t = *a;
		}
		op_pb(a, b);
	}
	sort_three(a);
	t1 = *b;
	if (t1->index < t1->next->index)
		op_s(b, "sb\n");
	op_pa(a, b);
	op_pa(a, b);
}

void	small_q(int argc, t_list **a, t_list **b)
{
	if (check_sort(a))
		return ;
	if (argc == 3)
		sort_two(a);
	if (argc == 4)
		sort_three(a);
	if (argc == 5)
		sort_four(a, b);
	if (argc == 6)
		sort_five(a, b);
}
