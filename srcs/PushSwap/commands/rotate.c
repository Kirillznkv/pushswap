#include "../push_swap.h"

void	ra(t_node *node)
{
	write(1, "ra\n", 3);
	rotate(&(node->a));
}

void	rb(t_node *node)
{
	write(1, "rb\n", 3);
	rotate(&(node->b));
}

void	rr(t_node *node)
{
	write(1, "rr\n", 3);
	rotate(&(node->a));
	rotate(&(node->b));
}
