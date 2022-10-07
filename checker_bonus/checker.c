#include "checker.h"
#include <fcntl.h>

void	switch_commands(char *command, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(command, "pa", ft_strlen("pa")))
		push(b, a, '0');
	else if (!ft_strncmp(command, "pb", ft_strlen("pb")))
		push(a, b, '0');
	else if (!ft_strncmp(command, "sa", ft_strlen("sa")))
		swap(a, '0');
	else if (!ft_strncmp(command, "sb", ft_strlen("sb")))
		swap(b, '0');
	else if (!ft_strncmp(command, "ra", ft_strlen("ra")))
		rotate(a, '0');
	else if (!ft_strncmp(command, "rb", ft_strlen("rb")))
		rotate(b, '0');
	else if (!ft_strncmp(command, "rra", ft_strlen("rra")))
		rev_rotate(a, '0');
	else if (!ft_strncmp(command, "rrb", ft_strlen("rrb")))
		rev_rotate(b, '0');
	else if (!ft_strncmp(command, "rrr", ft_strlen("rrr")))
		rrr(a, b, 0);
	else if (!ft_strncmp(command, "rr", ft_strlen("rr")))
		rr(a, b, 0);
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*command;

	b = NULL;
	a = init_stack(argc, argv);
	command = get_next_line(0);
	while (command)
	{
		switch_commands(command, &a, &b);
		command = get_next_line(0);
	}
	if (check_sorted(a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}
