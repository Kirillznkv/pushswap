#include "push_swap.h"

void	for_three(t_stack **stack, char stack_name)
{
	if (ft_lstsize(*stack) <= 3)
	{
		while (check_sorted(*stack) != 1)
		{
			if ((*stack)->idx < (*stack)->next->idx)
				rev_rotate(stack, stack_name);
			if ((*stack)->idx > (*stack)->next->idx
				&& ft_lstlast(*stack)->idx > (*stack)->idx)
				swap(stack, stack_name);
			if ((*stack)->idx > (*stack)->next->idx)
				rotate(stack, stack_name);
		}
	}
}

void	min_up(t_stack **a)
{
	while ((*a)->idx != search_min(*a))
	{
		if ((*a)->next->idx == search_min(*a))
			swap(a, 'a');
		else if (ft_lstlast(*a)->idx == search_min(*a)
			|| (*a)->idx < ft_lstsize(*a) / 2)
			rev_rotate(a, 'a');
		else if ((*a)->idx >= ft_lstsize(*a) / 2)
			rotate(a, 'a');
	}
}

void	for_five(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*a) <= 5)
	{
		while (ft_lstsize(*a) != 3)
		{
			min_up(a);
			if (!check_sorted(*a))
				push(a, &b, 'b');
			else
				break ;
		}
		for_three(a, 'a');
		if (b && b->next && b->idx < b->next->idx)
			swap(&b, 'b');
		while (b)
			push(&b, a, 'a');
	}
}
