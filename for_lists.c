#include "push_swap.h"

void	if_error(char **smth)
{
	for_free(smth);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_dubl(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->num == tmp->num)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

t_list	*list_a(int *argc, char **argv)
{
	t_list	*stack_a;
	int		i;
	int		flag;
	char	**ar;

	flag = 0;
	stack_a = NULL;
	if (*argc == 2)
		ar = if_one_line(argc, argv);
	else
		ar = if_many_argc(argc, argv);
	i = 0;
	while (i < *argc - 1)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(ar[i], &flag)));
		if (flag || check_dubl(stack_a))
			if_error(ar);
		i++;
	}
	for_free(ar);
	return (stack_a);
}

int	check_sort(t_list **a)
{
	t_list	*t;

	t = *a;
	while (t->next)
	{
		if (t->num > t->next->num)
			return (0);
		t = t->next;
	}
	return (1);
}

t_list	*for_index(t_list *a, int argc, char **argv)
{
	int		*num_a;
	int		i;
	t_list	*tmp;

	num_a = sorting_arr(arr_to_sort(&argc, argv), &argc);
	tmp = a;
	while (tmp != NULL)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (tmp->num == num_a[i])
			{
				tmp->index = i + 1;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(num_a);
	return (a);
}
