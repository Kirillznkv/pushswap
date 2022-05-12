#include "../push_swap.h"

void sort_3(t_node *stacks)
{

}

void sort_5(t_node *stacks)
{

}

void mega_sort(t_node *stacks)
{

}

void ft_sort(t_node *stacks, int n)
{
	if (is_sorted(stacks))
		return ;
	if (n == 2)
		sa(stacks);
	else if (n == 3)
		sort_3(stacks);
	else if (n == 5)
		sort_5(stacks);
	else
		mega_sort(stacks);
}
