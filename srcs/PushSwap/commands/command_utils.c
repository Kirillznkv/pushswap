#include "../push_swap.h"

static void del_node(t_stack *del)
{
	t_stack *beg;
	t_stack *end;

	beg = del->next;
	end = del->prev;
	if (beg == end)
	{
		beg->prev = NULL;
		beg->next = NULL;
	}
	else
	{
		beg->prev = end;
		end->next = beg;
	}
}

void	swap(t_stack *stack)
{
	int buf_int;

	if (stack == NULL || stack->next == NULL)
		return ;
	buf_int = stack->value;
	stack->value = stack->next->value;
	stack->next->value = buf_int;
}

void	push(t_stack **stack_in, t_stack **stack_out)
{
	t_stack *tmp;

	if (stack_in == NULL || stack_out == NULL || *stack_in == NULL)
		return ;
	tmp = *stack_in;
	*stack_in = tmp->next;
	if (tmp->next != NULL)
		del_node(tmp);
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*stack_out == NULL)
		*stack_out = tmp;
	else if ((*stack_out)->next != NULL)
	{
		tmp->next = *stack_out;
		tmp->prev = (*stack_out)->prev;
		(*stack_out)->prev->next = tmp;
		(*stack_out)->prev = tmp;
		*stack_out = tmp;
	}
	else
	{
		tmp->next = *stack_out;
		tmp->prev = *stack_out;
		(*stack_out)->next = tmp;
		(*stack_out)->prev = tmp;
		*stack_out = tmp;
	}
}

void	rotate(t_stack **stack)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
}

void	reverse_rotate(t_stack **stack)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->prev;
}
