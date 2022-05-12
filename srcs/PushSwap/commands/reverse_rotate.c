#include "../push_swap.h"

void	rra(t_node *node)
{
	reverse_rotate(&(node->a));
}

void	rrb(t_node *node)
{
	reverse_rotate(&(node->b));
}

void	rrr(t_node *node)
{
	reverse_rotate(&(node->a));
	reverse_rotate(&(node->b));
}
