#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "./lib/libft.h"

t_stack	*create_list(char **argv);
t_stack	*init_stack(int argc, char **argv);
void	arg_error_handler(int str);
void	mem_error_handler(void *mem, t_stack **a);
void	check_arguments(t_stack *a);
int		**create_array(t_stack **a);
void	sort_array(int **array);
void	insert_index(t_stack **a, int **array);
void	swap(t_stack **a, char stack_name);
void	push(t_stack **src, t_stack **dst, char dst_stack);
void	rotate(t_stack **stack, char stack_name);
void	rr(t_stack **a, t_stack **b, int m_flag);
void	rev_rotate(t_stack **stack, char stack_name);
void	rrr(t_stack **a, t_stack **b, int m_flag);
void	for_five(t_stack **a);
void	for_three(t_stack **stack, char stack_name);
void	big_sort(t_stack **a);
void	free_data(t_stack **a, int **array);
int		check_sorted_array(int **array);
int		check_sorted(t_stack *stack);
int		check_sorted_inter(t_stack *stack);
int		search_min(t_stack *stack);
int		search_max(t_stack *stack);
int		min_of_max(t_stack *a, int next_value);
int		current_index(t_stack *stack, int value);
int		half_stack_len(t_stack *stack);
int		idx_for_fewer_steps(t_stack *a, t_stack *b);

#endif //PUSH_SWAP_H
