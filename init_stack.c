#include "push_swap.h"

t_stack	*init_stack(int argc, char **argv)
{
	int		**array;
	t_stack	*a;

	if (argc == 1)
		exit(1);
	a = create_list(argv);
	check_arguments(a);
	array = create_array(&a);
	insert_index(&a, array);
	free_data(NULL, array);
	return (a);
}
