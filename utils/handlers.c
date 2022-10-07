#include "../push_swap.h"

void	arg_error_handler(int str)
{
	write(2, "ERROR: Invalid arguments\n ", 25);
	exit(str);
}

void	mem_error_handler(void *mem, t_stack **a)
{
	if (!mem)
	{
		ft_lstclear(a, free);
		write(2, "ERROR: Memory allocation error\n", 31);
		exit(12);
	}
}

int	check_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->idx != stack->next->idx - 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_inter(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->idx > stack->next->idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_array(int **array)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (array[j])
	{
		if (array[i][0] < array[j][0])
		{
			i++;
			j++;
		}
		else
			return (0);
	}
	return (1);
}
