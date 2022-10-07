#include "../push_swap.h"

void	free_split(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	add_new_node(char *new_content, t_stack **a)
{
	t_stack	*new_node;

	new_node = ft_lstnew(new_content);
	mem_error_handler(new_node, a);
	ft_lstadd_back(a, new_node);
}

void	add_node(char *argv, t_stack **a)
{
	int		i;
	char	**splited_arg;

	i = -1;
	if (ft_strchr(argv, ' '))
	{
		splited_arg = ft_split(argv, ' ');
		mem_error_handler(splited_arg, a);
		while (splited_arg[++i])
			add_new_node(splited_arg[i], a);
		free_split(splited_arg);
	}
	else
		add_new_node(argv, a);
}

t_stack	*create_list(char **argv)
{
	int		i;
	t_stack	*a;

	i = 1;
	a = NULL;
	while (argv[i])
	{
		add_node(argv[i], &a);
		i++;
	}
	return (a);
}
