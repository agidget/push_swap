#include "push_swap.h"

void	op_s(t_list **a, char *msg)
{
	t_list	*a1;
	t_list	*a2;

	a1 = *a;
	if (a1 == NULL || a1->next == NULL)
		return ;
	a2 = a1->next;
	a1->next = a2->next;
	a2->next = a1;
	*a = a2;
	write(1, msg, ft_strlen(msg));
}

void	op_r(t_list **a, char *msg)
{
	t_list	*a1;
	t_list	*a2;

	a1 = *a;
	if (a1 == NULL || a1->next == NULL)
		return ;
	a2 = *a;
	while (a2->next != NULL)
		a2 = a2->next;
	*a = a1->next;
	a1->next = NULL;
	a2->next = a1;
	write(1, msg, ft_strlen(msg));
}

void	op_rr(t_list **a, char *msg)
{
	t_list	*a1;
	t_list	*a2;

	a1 = *a;
	if (a1 == NULL || a1->next == NULL)
		return ;
	a2 = NULL;
	while (a1->next != NULL)
	{
		a2 = a1;
		a1 = a1->next;
	}
	a2->next = NULL;
	a1->next = *a;
	*a = a1;
	write(1, msg, ft_strlen(msg));
}

void	op_rr_double(t_list **a, t_list **b)
{
	op_rr(a, "");
	op_rr(b, "");
	write(1, "rrr\n", 4);
}
