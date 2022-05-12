#include "../push_swap.h"

void	sa(t_node *node)
{
	swap(node->a);
}

void	sb(t_node *node)
{
	swap(node->b);
}

void	ss(t_node *node)
{
	swap(node->a);
	swap(node->b);
}

void	pa(t_node *node)
{
	push(&(node->b), &(node->a));
}

void	pb(t_node *node)
{
	push(&(node->a), &(node->b));
}
