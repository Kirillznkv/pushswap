#include "push_swap.h"

void	up_together(t_stack **b, t_stack **a, int next, int min_max)
{
	if (current_index(*b, next) <= half_stack_len(*b)
		&& current_index(*a, min_max) <= half_stack_len(*a))
	{
		while ((*b)->idx != next && (*a)->idx != min_max)
			rr(a, b, 1);
	}
	else if (current_index(*b, next) > half_stack_len(*b)
		&& current_index(*a, min_max) > half_stack_len(*a))
	{
		while ((*b)->idx != next && (*a)->idx != min_max)
			rrr(a, b, 1);
	}
}

void	up_a_b(t_stack **b, t_stack **a, int next, int min_max)
{
	while ((*b)->idx != next)
	{
		if ((*b)->idx != next && current_index(*b, next) <= half_stack_len(*b))
			rotate(b, 'b');
		else if ((*b)->idx != next
			&& current_index(*b, next) > half_stack_len(*b))
			rev_rotate(b, 'b');
	}
	while ((*a)->idx != min_max)
	{
		if ((*a)->idx != min_max
			&& current_index(*a, min_max) > half_stack_len(*a))
			rev_rotate(a, 'a');
		else if ((*a)->idx != min_max
			&& current_index(*a, min_max) <= half_stack_len(*a))
			rotate(a, 'a');
	}
}

void	fill_b(t_stack **b, t_stack **a)
{
	while (!check_sorted_inter(*a) && ft_lstsize(*a) != 2)
	{
		if ((*a)->idx == search_min(*a) || (*a)->idx == search_max(*a))
		{
			rotate(a, 'a');
			continue ;
		}
		push(a, b, 'b');
	}
	while (ft_lstlast(*a)->idx != search_min(*a))
	{
		if (current_index(*a, search_min(*a)) <= half_stack_len(*a))
			rotate(a, 'a');
		else if (current_index(*a, search_min(*a)) > half_stack_len(*a))
			rev_rotate(a, 'a');
	}
}

void	big_sort(t_stack **a)
{
	t_stack	*b;
	int		next_value;
	int		min_of_max_a;

	b = NULL;
	fill_b(&b, a);
	while (b)
	{
		next_value = idx_for_fewer_steps(*a, b);
		min_of_max_a = min_of_max(*a, next_value);
		up_together(&b, a, next_value, min_of_max_a);
		up_a_b(&b, a, next_value, min_of_max_a);
		push(&b, a, 'a');
	}
	while ((*a)->idx != search_min(*a))
	{
		if (current_index(*a, search_min(*a)) <= half_stack_len(*a))
			rotate(a, 'a');
		if (current_index(*a, search_min(*a)) > half_stack_len(*a))
			rev_rotate(a, 'a');
	}
}
