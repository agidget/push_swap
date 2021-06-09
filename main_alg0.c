#include "push_swap.h"

t_main	*init_main_s(t_main *prime, t_list **a)
{
	prime->next = 1;
	prime->flag = 0;
	prime->max = max_in_list(a);
	prime->mid = prime->max / 2 + prime->next;
	return (prime);
}

void	sort_start(t_list **a, t_list **b, t_main *prime)
{
	t_list	*t;
	int		i;

	prime = init_main_s(prime, a);
	i = prime->max;
	while (i--)
	{
		t = *a;
		if (t->index <= prime->mid)
		{
			op_pb(a, b);
			if (t->index == prime->mid)
				prime->flag++;
		}
		else
			op_r(a, "ra\n");
	}
	prime->max = prime->mid;
	prime->mid = (prime->max - prime->next) / 2 + prime->next;
}

void	sort_part_one(t_list **a, t_list **b, t_main *prime, int *left_num)
{
	t_list	*t;
	int		i;

	sort_start(a, b, prime);
	i = prime->max;
	while (i--)
	{
		t = *b;
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
		else
		{
			op_r(b, "rb\n");
			*left_num = *left_num + 1;
		}
	}
}

void	for_part_two(t_list **a, t_list **b, t_main *prime, t_list *t)
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

void	sort_part_two(t_list **a, t_list **b, t_main *prime)
{
	t_list	*t;
	int		i;
	int		left_num;

	left_num = 0;
	sort_part_one(a, b, prime, &left_num);
	t = *b;
	while (t != NULL)
	{
		prime->max = prime->mid - 1;
		prime->mid = (prime->max - prime->next) / 2 + prime->next;
		prime->flag++;
		i = left_num;
		while (i--)
		{
			if (t->index >= prime->mid || t->index == prime->next)
			{
				for_part_two(a, b, prime, t);
				left_num--;
			}
			else
				op_r(b, "rb\n");
			t = *b;
		}
	}
}
