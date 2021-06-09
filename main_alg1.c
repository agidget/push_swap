#include "push_swap.h"

void	if_many_one(t_list **a, t_list **b, t_main *prime, int *q)
{
	t_list	*t;
	int		i;

	*q = q_one_flag(a);
	i = *q;
	prime->max = max_in_last_heap(a, *q);
	prime->mid = (prime->max - prime->next) / 2 + prime->next;
	while (i--)
	{
		t = *a;
		if (t->index <= prime->mid)
		{
			op_pb(a, b);
			(*q)--;
		}
		else if (t->index > prime->mid)
		{
			if ((t->index == prime->next) && (last_ind(a) == prime->next - 1))
				prime->next++;
			op_r(a, "ra\n");
		}
	}
}

void	if_many_end(t_list **a, t_list **b, t_main *prime)
{
	t_list	*tb;

	tb = *b;
	if (tb->index != prime->next)
		op_rr(b, "rrb\n");
	op_pa(a, b);
	op_r(a, "ra\n");
	prime->next++;
}

void	if_many_left(t_list **a, t_list **b, t_main *prime)
{
	t_list	*t;
	t_list	*tb;
	int		i;
	int		q;

	i = 0;
	q = 0;
	if_many_one(a, b, prime, &q);
	tb = *b;
	while (q)
	{
		t = *a;
		while (tb->index != prime->next && i < q)
		{
			op_rr_double(a, b);
			tb = *b;
			i++;
		}
		if (i == q)
			break ;
		op_rr(a, "rra\n");
		q--;
	}
	if_many_end(a, b, prime);
}

void	for_sort_heaps(t_list **a, t_list **b, t_main *prime, int q)
{
	if (q == 1 || q == 2)
		if_left_ot(a, prime, q);
	else if (q == 3)
		if_left_three(a, b, prime, q);
	else
		if_many_left(a, b, prime);
}

void	sort_heaps(t_list **a, t_list **b, t_main *prime)
{
	int		q;
	t_list	*t;
	t_list	*tb;

	sort_part_two(a, b, prime);
	t = *a;
	tb = *b;
	while (t->flag != 0 || tb != NULL)
	{
		if (tb == NULL)
		{
			q = q_one_flag(a);
			for_sort_heaps(a, b, prime, q);
		}
		else
		{
			q = q_in_list(b);
			if (q <= 3)
				sort_small_in_b(a, b, prime, q);
			else if (q > 3)
				sort_big_in_b(a, b, prime, q);
		}
		t = *a;
		tb = *b;
	}
}
