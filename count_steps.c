#include "push_swap.h"

int	count_steps(t_stack *a, t_stack *b, int idx_b)
{
	int	min_of_max_a;
	int	current_idx_a;
	int	current_idx_b;
	int	steps;

	steps = 1;
	min_of_max_a = min_of_max(a, idx_b);
	current_idx_a = current_index(a, min_of_max_a);
	current_idx_b = current_index(b, idx_b);
	if (current_idx_b <= half_stack_len(b))
		steps += current_idx_b - 1;
	else if (current_idx_b > half_stack_len(b))
		steps += ft_lstsize(b) - current_idx_b + 1;
	if (current_idx_a <= half_stack_len(a))
		steps += current_idx_a - 1;
	else if (current_idx_a > half_stack_len(a))
		steps += ft_lstsize(a) - current_idx_a + 1;
	return (steps);
}

int	idx_for_fewer_steps(t_stack *a, t_stack *b)
{
	int		steps_num_true;
	int		steps_num;
	int		true_idx;
	t_stack	*tmp;

	tmp = b;
	true_idx = tmp->idx;
	steps_num_true = count_steps(a, b, tmp->idx);
	if (steps_num_true > 2)
	{
		tmp = tmp->next;
		while (tmp)
		{
			steps_num = count_steps(a, b, tmp->idx);
			if (steps_num < steps_num_true)
			{
				steps_num_true = steps_num;
				true_idx = tmp->idx;
			}
			tmp = tmp->next;
		}
	}
	return (true_idx);
}
