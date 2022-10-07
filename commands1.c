#include "push_swap.h"

void	push(t_stack **src, t_stack **dst, char dst_stack)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, tmp);
	if (dst_stack == 'a')
		write(1, "pa\n", 3);
	else if (dst_stack == 'b')
		write(1, "pb\n", 3);
	else
		return ;
}

void	swap(t_stack **stack, char stack_name)
{
	t_stack	*tmp;

	if ((*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = (*stack);
		(*stack) = tmp;
		if (stack_name == 'a')
			write(1, "sa\n", 3);
		else if (stack_name == 'b')
			write(1, "sb\n", 3);
		else
			return ;
	}
}
