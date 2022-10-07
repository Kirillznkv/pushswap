#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = init_stack(argc, argv);
	for_five(&a);
	if (ft_lstsize(a) > 5)
		big_sort(&a);
	ft_lstclear(&a, free);
	return (0);
}
