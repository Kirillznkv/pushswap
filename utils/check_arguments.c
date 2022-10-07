#include "../push_swap.h"

size_t	larger_len(char *a_arg, char *cmp_arg)
{
	size_t	len_a;
	size_t	len_cmp;

	len_a = ft_strlen(a_arg);
	len_cmp = ft_strlen(cmp_arg);
	if (len_a >= len_cmp)
		return (len_a);
	else
		return (len_cmp);
}

void	check_duplicates(t_stack *a)
{
	t_stack	*cmp;

	cmp = NULL;
	if (a->next)
		cmp = a->next;
	while (a)
	{
		while (cmp)
		{
			if (!ft_strncmp(a->argv, cmp->argv, larger_len(a->argv, cmp->argv)))
				arg_error_handler(15);
			cmp = cmp->next;
		}
		a = a->next;
		if (a)
			cmp = a->next;
	}
}

void	check_digits(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->argv[0] == '-' && a->argv[1] > 48 && a->argv[1] < 58)
			i++;
		if (a->argv[0] == '0' && a->argv[1] != '\0')
			arg_error_handler(33);
		while (a->argv[i])
		{
			if (a->argv[i] > 47 && a->argv[i] < 58)
				i++;
			else
				arg_error_handler(39);
		}
		i = 0;
		a = a->next;
	}
}

void	check_arguments(t_stack *a)
{
	check_digits(a);
	check_duplicates(a);
}
