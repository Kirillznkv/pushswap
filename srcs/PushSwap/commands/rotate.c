#include "../push_swap.h"

void	ra(t_node *node)
{
	rotate(&(node->a));
}

void	rb(t_node *node)
{
	rotate(&(node->b));
}

void	rr(t_node *node)
{
	rotate(&(node->a));
	rotate(&(node->b));
}
