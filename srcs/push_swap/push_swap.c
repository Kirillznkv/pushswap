/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:05:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/09 20:19:01 by kshanti          ###   ########.fr       */
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

void		swap_100_2000(t_list *tmp1, t_list *tmp2)
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
				while (tmp1->next && tmp1->value < tmp1->next->value && tmp1->value < last->value && (!tmp2 || tmp1->value > tmp2->value))
				{
					push(&tmp2, &tmp1);
					write(1, "pb\n", 3);
				}
				if (tmp1->value < last->value && (!tmp2 || tmp1->value > tmp2->value))
				{
					push(&tmp2, &tmp1);
					write(1, "pb\n", 3);
				}
				else if (tmp1->next && !tmp1->next->next && tmp1->value < last->value)
				{
					swap(tmp1);
					write(1, "sa\n", 3);
				}
				reverse_rotate(&tmp1);
				write(1, "rra\n", 4);
			}
		}
	}
}

/*-------------------------------FUCK-----------------------------------------*/
int			bad_check_list_ps(t_list *tmp1, t_list *tmp2)
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
		if (beg->value < beg->next->value)
			return (0);
		beg = beg->next;
	}
	if (tmp2 == NULL)
		return (1);
	return (0);
}

int			ft_lstsize(t_list *lst)
{
	t_list	*beg;
	int		size;

	size = 0;
	beg = lst;
	while (beg)
	{
		beg = beg->next;
		size++;
	}
	return (size);
}

int			find_min(t_list *tmp)
{
	int		min;
	int		min_i;
	int		i;

	i = 0;
	min_i = -1;
	min = __INT32_MAX__;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_i = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_i);
}

void		swap_100_v2(t_list *tmp1, t_list *tmp2)
{
	int		n;

	while (!check_list_ps(tmp1, tmp2))
	{
		n = find_min(tmp1);
		if (n <= ft_lstsize(tmp1))
		{
			while (n-- > 0)
			{
				rotate(&tmp1);
				write(1, "ra\n", 3);
			}
		}
		else
		{
			n = ft_lstsize(tmp1) - n;
			while (n-- > 0)
			{
				reverse_rotate(&tmp1);
				write(1, "rra\n", 4);
			}
		}
		if (!tmp1->next || bad_check_list_ps(tmp1, NULL))
		{
			while (tmp2)
			{
				push(&tmp1, &tmp2);
				write(1, "pa\n", 3);
			}
		}
		else
		{
			push(&tmp2, &tmp1);
				write(1, "pb\n", 3);
		}
	}
	printf("OK\n");
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
				// if (tmp1->next && tmp1->next->value > tmp1->value && last->value < tmp1->next->value)
				// {
				// 	reverse_rotate(&tmp1);
				// 	write(1, "rra\n", 4);
				// 	swap(tmp1);
				// 	write(1, "sa\n", 3);
				// 	continue ;
				// }
				while (tmp1->next && tmp1->value < tmp1->next->value && tmp1->value < last->value && (!tmp2 || tmp1->value > tmp2->value))
				{
					push(&tmp2, &tmp1);
					write(1, "pb\n", 3);
				}
				if (tmp1->value < last->value && (!tmp2 || tmp1->value > tmp2->value))
				{
					push(&tmp2, &tmp1);
					write(1, "pb\n", 3);
				}
				else if (tmp1->next && !tmp1->next->next && tmp1->value < last->value)
				{
					swap(tmp1);
					write(1, "sa\n", 3);
				}
				reverse_rotate(&tmp1);
				write(1, "rra\n", 4);
			}
		}
	}
}

/*-------------------------------main-----------------------------------------*/
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