#include "push_swap.h"

void	last_sort_one(t_list **a, t_list **b, t_main *prime, int *q)
{
	t_list	*t;
	int		i;

	sort_heaps(a, b, prime);
	*q = q_in_last(a);
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

void	last_sort_two(t_list **a, t_list **b, t_main *prime)
{
	t_list	*t;
	t_list	*tb;
	int		q;
	int		i;

	q = 0;
	last_sort_one(a, b, prime, &q);
	i = 0;
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

void	last_sort_three(t_list **a, t_list **b, t_main *prime)
{
	t_list	*t;
	int		i;
	int		q;

	last_sort_two(a, b, prime);
	q = q_in_list(b);
	t = *b;
	while (t != NULL)
	{
		prime->max = prime->mid - 1;
		prime->mid = (prime->max - prime->next) / 2 + prime->next;
		prime->flag++;
		i = q;
		while (i--)
		{
			if (t->index >= prime->mid || t->index == prime->next)
			{
				for_part_two(a, b, prime, t);
				q--;
			}
			else
				op_r(b, "rb\n");
			t = *b;
		}
	}
}

void	last_sort_four(t_list **a, t_list **b, t_main *prime)
{
	int		q;
	t_list	*t;
	t_list	*tb;

	last_sort_three(a, b, prime);
	t = *a;
	tb = *b;
	while (t->index != 1 || tb != NULL)
	{
		if (tb == NULL)
		{
			q = q_not_one_index(a);
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
