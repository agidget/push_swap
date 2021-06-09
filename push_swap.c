#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_main	*pr;
	int		bo;

	bo = argc;
	if (argc == 1)
		return (0);
	a = list_a(&argc, argv);
	if (check_sort(&a))
		return (0);
	a = for_index(a, bo, argv);
	init_flags(a);
	b = NULL;
	pr = malloc(sizeof(t_main));
	if (argc <= 6)
		small_q(argc, &a, &b);
	else
		last_sort_four(&a, &b, pr);
	free(pr);
}
