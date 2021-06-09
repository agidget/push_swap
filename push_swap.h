#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	int				index;
	int				flag;
	struct s_list	*next;
}	t_list;

typedef struct s_main
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}	t_main;

int		ft_atoi(const char *str, int *flag);
t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	if_error(char **smth);
t_list	*list_a(int *argc, char **argv);
int		check_sort(t_list **a);
int		check_dubl(t_list *a);
int		*arr_to_sort(int *argc, char **argv);
int		*sorting_arr(int *num_a, int *argc);
t_list	*for_index(t_list *a, int argc, char **argv);
int		ft_strlen(char *str);
void	op_s(t_list **a, char *msg);
void	op_r(t_list **a, char *msg);
void	op_rr(t_list **a, char *msg);
void	op_pb(t_list **a, t_list **b);
void	op_pa(t_list **a, t_list **b);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
void	*for_free(char **new);
char	**if_one_line(int *argc, char **argv);
char	**if_many_argc(int *argc, char **argv);
void	init_flags(t_list *a);
void	sort_two(t_list **a);
void	sort_three(t_list **a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
int		min_in_list(t_list **a);
void	small_q(int argc, t_list **a, t_list **b);
int		max_in_list(t_list **a);
void	sort_start(t_list **a, t_list **b, t_main *prime);
t_main	*init_main_s(t_main *prime, t_list **a);
void	sort_part_one(t_list **a, t_list **b, t_main *prime, int *left_num);
void	sort_part_two(t_list **a, t_list **b, t_main *prime);
void	if_left_ot(t_list **a, t_main *prime, int q);
void	if_left_three(t_list **a, t_list **b, t_main *prime, int q);
void	if_many_left(t_list **a, t_list **b, t_main *prime);
void	sort_heaps(t_list **a, t_list **b, t_main *prime);
void	sort_small_in_b(t_list**a, t_list **b, t_main *prime, int q);
void	for_part_two(t_list **a, t_list **b, t_main *prime, t_list *t);
void	sort_big_in_b(t_list **a, t_list **b, t_main *prime, int q);
int		q_one_flag(t_list **a);
int		q_in_list(t_list **b);
int		q_in_last(t_list **a);
void	for_sort_heaps(t_list **a, t_list **b, t_main *prime, int q);
void	op_rr_double(t_list **a, t_list **b);
void	last_sort_one(t_list **a, t_list **b, t_main *prime, int *q);
void	last_sort_two(t_list **a, t_list **b, t_main *prime);
void	for_part_three(t_list **a, t_list **b, t_main *prime, t_list *t);
void	last_sort_three(t_list **a, t_list **b, t_main *prime);
int		q_not_one_index(t_list **a);
void	last_sort_four(t_list **a, t_list **b, t_main *prime);
int		max_in_last_heap(t_list **a, int q);
int		last_ind(t_list **a);
void	if_many_end(t_list **a, t_list **b, t_main *prime);
int		check_int(t_list *a);
int		int_error(void);

#endif
