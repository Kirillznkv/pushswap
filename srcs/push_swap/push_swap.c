/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:05:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/07 03:09:10 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int			check_list_ps(t_list *tmp1, t_list *tmp2)
{
	t_list		*beg;

	beg = tmp1;
	while (beg && beg->next)
	{
		if (beg->value == beg->next->value)
		{
			printf("Error:\nПовторяющиеся аргументы\n");
			exit(1);
		}
		if (beg->value > beg->next->value)
			return (0);
		beg = beg->next;
	}
	if (tmp2 == NULL)
		return (1);
	return (0);
}

void		swap_3(t_list *tmp)
{
	int		a;

	a = tmp->value;
	if (a < tmp->next->value && a < tmp->next->next->value)
		write(1, "ra\nsa\nrra\n", 11);
	else if (a > tmp->next->value && a > tmp->next->next->value)
	{
		rotate(&tmp);
		if (check_list_ps(tmp, NULL))
			write(1, "ra\n", 4);
		else
			write(1, "ra\nsa\n", 7);
	}
	else if (a > tmp->next->value)
		write(1, "sa\n", 4);
	else if (a < tmp->next->value && a != tmp->next->next->value)
		write(1, "rra\n", 5);
	else
	{
		printf("Error:\nПовторяющиеся аргументы\n");
		exit(1);
	}
}

void		push_swap(t_list *tmp1, t_list *tmp2, int n)
{
	char	*res;

	if (check_list_ps(tmp1, tmp2))
		write(1, "", 1);
	else if (n == 2)
		write(1, "sa\n", 4);
	else if (n == 3)
		swap_3(tmp1);
}