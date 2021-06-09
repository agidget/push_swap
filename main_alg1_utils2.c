#include "push_swap.h"

int	q_one_flag(t_list **a)
{
	int		q;
	t_list	*t;

	q = 1;
	t = *a;
	while (t->flag == t->next->flag && t->next->index != 1)
	{
		q++;
		t = t->next;
	}
	return (q);
}

int	q_in_list(t_list **b)
{
	int		num;
	t_list	*lst;

	num = 0;
	lst = *b;
	while (lst)
	{
		num++;
		lst = lst->next;
	}
	return (num);
}

void	if_left_ot(t_list **a, t_main *prime, int q)
{
	t_list	*t;

	t = *a;
	if (q == 1)
		op_r(a, "ra\n");
	if (q == 2)
	{
		if (t->index != prime->next)
			op_s(a, "sa\n");
		op_r(a, "ra\n");
		op_r(a, "ra\n");
		prime->next++;
	}
	prime->next++;
}

void	if_left_three(t_list **a, t_list **b, t_main *prime, int q)
{
	t_list	*t;
	t_list	*tb;
	int		q1;

	q1 = q + 1;
	while (--q1)
	{
		t = *a;
		if (t->index != prime->next)
			op_pb(a, b);
		else
		{
			op_r(a, "ra\n");
			prime->next++;
		}
	}
	tb = *b;
	while (tb != NULL)
	{
		op_pa(a, b);
		tb = *b;
		q1++;
	}
	if (q1)
		if_left_ot(a, prime, q1);
}
