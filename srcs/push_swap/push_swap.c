/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:05:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/08 00:21:17 by kshanti          ###   ########.fr       */
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
		write(1, "sa\nra\n", 11);
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

void		out(t_list *tmp)
{
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n------------------------------------\n");
}

void		swap_100(t_list *tmp1, t_list *tmp2)
{
	t_list	*last;

	while (!check_list_ps(tmp1, tmp2))
	{
		if (tmp1->next == NULL)
		{
			while (tmp2)
			{
				push(&tmp1, &tmp2);
				write(1, "pa\n", 3);
			}
		}
		else
		{
			last = put_last_list(tmp1);
			if (last->value < tmp1->value && (tmp2 == NULL || last->value > tmp2->value))
			{
				reverse_rotate(&tmp1);
				write(1, "rra\n", 4);
			}
			else if (last->value < tmp1->value)
			{
				while (tmp2 && last->value < tmp2->value)
				{
					push(&tmp1, &tmp2);
					write(1, "pa\n", 3);
				}
				reverse_rotate(&tmp1);
				write(1, "rra\n", 4);
			}
			else if (last->value > tmp1->value)
			{
				while (tmp1->next && tmp1->value < tmp1->next->value && tmp1->value < last->value)
				{
					push(&tmp2, &tmp1);
					write(1, "pb\n", 3);
				}
				if (tmp1->value < last->value)
				{
					push(&tmp2, &tmp1);
					write(1, "pb\n", 3);
				}
			}
		}
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
	else
		swap_100(tmp1, tmp2);
}