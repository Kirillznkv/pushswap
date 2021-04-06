/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:31:16 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/06 23:32:24 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			nicelst(char *str, int *value)
{
	int		i;
	int		dig;

	i = 0;
	dig = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		dig++;
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0' || !dig)
		return (0);
	*value = ft_atoi(str);
	return (1);
}

t_list		*init(char **argv, int n)
{
	int		i;
	int		value;
	t_list	*tmp;

	i = 0;
	tmp = NULL;
	while (++i <= n)
	{
		if (!nicelst(argv[i], &value))
		{
			printf("Error:\nНеверный аргумент\n");
			exit(1);
		}
		add_back(&tmp, lstnew(value));
	}
	return (tmp);
}

int		main(int argc, char **argv)
{
	t_list		*tmp1;
	t_list		*tmp2;

	if (argc > 1)
	{
		tmp1 = init(argv, argc - 1);
		tmp2 = NULL;
		checker(tmp1, tmp2);
	}
	return (0);
}
