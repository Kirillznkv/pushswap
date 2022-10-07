#include "push_swap.h"

void	free_data(t_stack **a, int **array)
{
	int	i;

	i = 0;
	if (a)
		ft_lstclear(a, free);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	**create_empty_array(t_stack **a)
{
	int	i;
	int	**empty_array;

	i = 0;
	empty_array = (int **) ft_calloc(ft_lstsize(*a) + 1, sizeof (int *));
	mem_error_handler(empty_array, a);
	while (i != ft_lstsize(*a))
	{
		empty_array[i] = (int *) ft_calloc(1, sizeof (int));
		mem_error_handler(empty_array[i], a);
		i++;
	}
	return (empty_array);
}

int	**create_array(t_stack **a)
{
	int		**unsorted_array;
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	unsorted_array = create_empty_array(a);
	while (*a)
	{
		unsorted_array[i][0] = ft_atoi((*a)->argv);
		(*a)->dgt = unsorted_array[i][0];
		i++;
		*a = (*a)->next;
	}
	*a = tmp;
	if (check_sorted_array(unsorted_array) == 1)
	{
		free_data(a, unsorted_array);
		exit(0);
	}
	return (unsorted_array);
}
