#include "push_swap.h"

static int init(t_stack **stack, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_elem(argv[i]))
			return (-1);
		add_elem(stack, ft_atoi(argv[i]));
		++i;
	}
	return (0);
}

static void output(t_node *stacks)//del
{
	printf("Stack a: ");
	t_stack *tmp = stacks->a;
	if (tmp && tmp->prev)
		tmp->prev->next = NULL;
	while (tmp )
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
	printf("Stack b: ");
	tmp = stacks->b;
	if (tmp && tmp->prev)
		tmp->prev->next = NULL;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_node stacks;

	if (argc == 1)
		return (0);
	stacks.a = NULL;
	stacks.b = NULL;
	if (init(&(stacks.a), argc, argv) == -1)
	{
		write(2, "Error arguments\n", 17);
		return (1);
	}
	output(&stacks);
	return (0);
}