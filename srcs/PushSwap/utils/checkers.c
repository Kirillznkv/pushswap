#include "../push_swap.h"

int is_sorted(t_node *stacks)
{
	int flag;
	t_stack *tmp;

	if (stacks->b != NULL)
		return (0);
	flag = 1;
	tmp = stacks->a;
	while (tmp && tmp->next && (flag || tmp->next != stacks->a))
	{
		if (tmp->next->value < tmp->value)
			return (0);
		if (tmp->next->value == tmp->value)
		{
			write(2, "Error arguments\n", 17);
			exit(1);
		}
		tmp = tmp->next;
		flag = 0;
	}
}
