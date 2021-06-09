#include "push_swap.h"
#include <stdio.h>

char	**if_one_line(int *argc, char **argv)
{
	int		j;
	char	**my_ar;

	if (argv[1][0] == '\0')
		exit (1);
	my_ar = ft_split(argv[1], ' ');
	j = 0;
	while (my_ar[j++])
		;
	*argc = j;
	return (my_ar);
}

char	**if_many_argc(int *argc, char **argv)
{
	int		i;
	char	**ar;

	i = 0;
	ar = malloc(sizeof(char *) * (*argc));
	while (i < *argc - 1)
	{
		ar[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	ar[i] = 0;
	return (ar);
}

int	*arr_to_sort(int *argc, char **argv)
{
	int		*num_a;
	int		i;
	int		flag;
	char	**ar;

	if (*argc == 2)
		ar = if_one_line(argc, argv);
	else
		ar = if_many_argc(argc, argv);
	num_a = malloc(sizeof(int) * (*argc - 1));
	if (!num_a)
		write (2, "Error\n", 6);
	i = 0;
	flag = 0;
	while (i < *argc - 1)
	{
		num_a[i] = ft_atoi(ar[i], &flag);
		if (flag)
			if_error(ar);
		i++;
	}
	for_free(ar);
	return (num_a);
}

int	*sorting_arr(int *num_a, int *argc)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = 0;
	while (i < *argc - 2)
	{
		j = 0;
		while (j < *argc - 2 - i)
		{
			if (num_a[j] > num_a[j + 1])
			{
				tmp = num_a[j];
				num_a[j] = num_a[j + 1];
				num_a[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (num_a);
}
