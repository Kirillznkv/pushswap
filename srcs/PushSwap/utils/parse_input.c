#include "../push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_elem(char *str)
{
	int i;

	i = 0;
	while (str && str[i] == ' ')
		i++;
	while (str && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str && ft_isdigit(str[i]))
		i++;
	while (str && str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

void	add_elem(t_stack **stack, int elem)
{
	t_stack *tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp == NULL)
	{
		write(2, "Error malloc\n", 14);
		exit(1);
	}
	tmp->value = elem;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (*stack == NULL)
		*stack = tmp;
	else if ((*stack)->next != NULL)
	{
		tmp->prev = (*stack)->prev;
		tmp->next = *stack;
		(*stack)->prev->next = tmp;
		(*stack)->prev = tmp;
	}
	else
	{
		tmp->next = *stack;
		tmp->prev = *stack;
		(*stack)->next = tmp;
		(*stack)->prev = tmp;
	}
}
