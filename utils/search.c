#include "../push_swap.h"

int	search_min(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	while (stack)
	{
		tmp = stack->next;
		while (tmp && stack->idx < tmp->idx)
			tmp = tmp->next;
		if (tmp == NULL)
			break ;
		stack = stack->next;
	}
	return (stack->idx);
}

int	search_max(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	while (stack)
	{
		tmp = stack->next;
		while (tmp && stack->idx > tmp->idx)
			tmp = tmp->next;
		if (tmp == NULL)
			break ;
		stack = stack->next;
	}
	return (stack->idx);
}

int	current_index(t_stack *stack, int value)
{
	int	current;

	current = 1;
	while (stack->idx != value)
	{
		stack = stack->next;
		current++;
	}
	return (current);
}

int	min_of_max(t_stack *a, int next_value)
{
	int	min;

	min = search_max(a);
	while (a)
	{
		if (a->idx > next_value && a->idx < min)
			min = a->idx;
		a = a->next;
	}
	return (min);
}

int	half_stack_len(t_stack *stack)
{
	if (ft_lstsize(stack) % 2)
		return (ft_lstsize(stack) / 2 + 1);
	return (ft_lstsize(stack) / 2);
}
