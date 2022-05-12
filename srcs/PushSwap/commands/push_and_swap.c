#include "../push_swap.h"

void	sa(t_node *node)
{
	write(1, "sa\n", 3);
	swap(node->a);
}

void	sb(t_node *node)
{
	write(1, "sb\n", 3);
	swap(node->b);
}

void	ss(t_node *node)
{
	write(1, "ss\n", 3);
	swap(node->a);
	swap(node->b);
}

void	pa(t_node *node)
{
	write(1, "pa\n", 3);
	push(&(node->b), &(node->a));
}

void	pb(t_node *node)
{
	write(1, "pb\n", 3);
	push(&(node->a), &(node->b));
}
