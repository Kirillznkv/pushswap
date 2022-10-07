#include "push_swap.h"

void	sort_array(int **array)
{
	int	i;
	int	buf;

	i = 0;
	buf = 0;
	while (!check_sorted_array(array))
	{
		i = 0;
		while (array[i + 1])
		{
			if (array[i][0] > array[i + 1][0])
			{
				buf = array[i][0];
				array[i][0] = array[i + 1][0];
				array[i + 1][0] = buf;
			}
			i++;
		}
	}
}

void	insert_index(t_stack **a, int **array)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	sort_array(array);
	while (array[i])
	{
		*a = tmp;
		while (*a)
		{
			if ((*a)->dgt == array[i][0])
			{
				(*a)->idx = i + 1;
				break ;
			}
			*a = (*a)->next;
		}
		i++;
	}
	*a = tmp;
}
