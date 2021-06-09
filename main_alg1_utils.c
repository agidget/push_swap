#include "push_swap.h"

static void	sort_two_in_b(t_list **b)
{
	t_list	*tb;

	tb = *b;
	if (tb->index < tb->next->index)
		op_s(b, "sb\n");
}

static void	sort_thr_in_b(t_list **b)
{
	t_list	*t;

	t = *b;
	if ((t->index > t->next->index) && (t->index < t->next->next->index)
		&& (t->next->index < t->next->next->index))
		op_rr(b, "rrb\n");
	else if ((t->index < t->next->index) && (t->index < t->next->next->index)
		&& (t->next->index < t->next->next->index))
	{
		op_s(b, "sb\n");
		op_rr(b, "rrb\n");
	}
	else if ((t->index > t->next->index) && (t->index > t->next->next->index)
		&& (t->next->index < t->next->next->index))
	{
		op_s(b, "sb\n");
		op_r(b, "rb\n");
	}
	else if ((t->index < t->next->index) && (t->index < t->next->next->index)
		&& (t->next->index > t->next->next->index))
		op_r(b, "rb\n");
	else if ((t->index < t->next->index) && (t->index > t->next->next->index)
		&& (t->next->index > t->next->next->index))
		op_s(b, "sb\n");
}

void	sort_small_in_b(t_list **a, t_list **b, t_main *p, int q)
{
	int	i;

	i = q;
	if (q == 1)
	{
		op_pa(a, b);
		op_r(a, "ra\n");
		p->next++;
		return ;
	}
	if (q == 2)
		sort_two_in_b(b);
	else if (q == 3)
	{
		sort_thr_in_b(b);
		p->next++;
	}
	p->next += 2;
	while (q--)
		op_pa(a, b);
	while (i--)
		op_r(a, "ra\n");
}

void	sort_big_in_b(t_list **a, t_list **b, t_main *prime, int q)
{
	t_list	*tb;

	tb = *b;
	prime->max = max_in_list(b);
	prime->mid = prime->max - (q - 1) / 2;
	while (q--)
	{
		if (tb->index >= prime->mid || tb->index == prime->next)
		{
			if (tb->index >= prime->mid)
				op_pa(a, b);
			else if (tb->index == prime->next)
			{
				op_pa(a, b);
				op_r(a, "ra\n");
				prime->next++;
			}
			tb->flag++;
		}
		else
			op_r(b, "rb\n");
		tb = *b;
	}
}
