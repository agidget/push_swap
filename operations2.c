#include "push_swap.h"

void	op_pa(t_list **a, t_list **b)
{
	t_list	*b_head;
	t_list	*t;

	if (*b == NULL)
		return ;
	t = *b;
	b_head = t->next;
	t->next = NULL;
	ft_lstadd_front(a, t);
	*b = b_head;
	write(1, "pa\n", 3);
}

void	op_pb(t_list **a, t_list **b)
{
	t_list	*a_head;
	t_list	*t;

	if (*a == NULL)
		return ;
	t = *a;
	a_head = t->next;
	t->next = NULL;
	ft_lstadd_front(b, t);
	*a = a_head;
	write(1, "pb\n", 3);
}
