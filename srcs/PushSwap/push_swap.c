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
	int flag = 1;
	while (tmp && (flag || tmp != stacks->a))
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
		flag = 0;
	}
	printf("\n");
	printf("Stack b: ");
	tmp = stacks->b;
	flag = 1;
	while (tmp && (flag || tmp != stacks->b))
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
		flag = 0;
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

	pb(&stacks);
	pb(&stacks);
	pb(&stacks);
	printf("\n");
	output(&stacks);

	ss(&stacks);
	printf("\n");
	output(&stacks);

	rr(&stacks);
	printf("\n");
	output(&stacks);
	return (0);
}