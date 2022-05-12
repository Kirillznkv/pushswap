#include "../push_swap.h"

void	rra(t_node *node)
{
	write(1, "rra\n", 4);
	reverse_rotate(&(node->a));
}

void	rrb(t_node *node)
{
	write(1, "rrb\n", 4);
	reverse_rotate(&(node->b));
}

void	rrr(t_node *node)
{
	write(1, "rrr\n", 4);
	reverse_rotate(&(node->a));
	reverse_rotate(&(node->b));
}
