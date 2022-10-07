#include "push_swap.h"

void	rotate(t_stack **stack, char stack_name)
{
	t_stack	*tmp;

	if (!(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	ft_lstlast(tmp)->next = *stack;
	*stack = tmp;
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	else if (stack_name == 'b')
		write(1, "rb\n", 3);
	else
		return ;
}

void	rr(t_stack **a, t_stack **b, int m_flag)
{
	rotate(a, 'w');
	rotate(b, 'w');
	if (m_flag)
		write (1, "rr\n", 3);
}

void	rev_rotate(t_stack **stack, char stack_name)
{
	t_stack	*tmp;
	t_stack	*penult;
	int		i;

	penult = *stack;
	i = ft_lstsize(*stack);
	while (i > 2)
	{
		penult = penult->next;
		i--;
	}
	tmp = ft_lstlast(*stack);
	penult->next = NULL;
	ft_lstadd_front(stack, tmp);
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else if (stack_name == 'b')
		write(1, "rrb\n", 4);
	else
		return ;
}

void	rrr(t_stack **a, t_stack **b, int m_flag)
{
	rev_rotate(a, 'w');
	rev_rotate(b, 'w');
	if (m_flag)
		write (1, "rrr\n", 4);
}
