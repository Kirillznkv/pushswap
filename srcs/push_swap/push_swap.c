/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:05:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/12 20:49:59 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int			ft_lstsize(t_list *lst);////////////////////////////////////////////
void		out(t_list *tmp);////////////////////////////////////////////

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

void		swap_3(t_list **tmp)
{
	int		a;

	if(check_list_ps(*tmp, NULL))
		return ;
	a = (*tmp)->value;
	if (a < (*tmp)->next->value && a < (*tmp)->next->next->value)
	{
		swap(*tmp);
		rotate(tmp);
		write(1, "sa\nra\n", 6);
	}
	else if (a > (*tmp)->next->value && a > (*tmp)->next->next->value)
	{
		rotate(tmp);
		write(1, "ra\n", 3);
		if (!check_list_ps(*tmp, NULL))
		{
			swap(*tmp);
			write(1, "sa\n", 3);
		}
	}
	else if (a > (*tmp)->next->value)
	{
		swap(*tmp);
		write(1, "sa\n", 3);
	}
	else if (a < (*tmp)->next->value && a != (*tmp)->next->next->value)
	{
		reverse_rotate(tmp);
		write(1, "rra\n", 4);
	}
	else
	{
		printf("Error:\nПовторяющиеся аргументы\n");
		exit(1);
	}
}

void		min_max(t_list *tmp, int *min, int *max)
{
	t_list	*beg;

	*min = __INT32_MAX__;
	*max = - __INT32_MAX__ - 1;
	beg = tmp;
	while (beg)
	{
		if (beg->value < *min)
			*min = beg->value;
		if (beg->value > *max)
			*max = beg->value;
		beg = beg->next;
	}
}

int			second_stack(t_list *tmp, int i)
{
	if (i <= ft_lstsize(tmp) / 2)
		return (i);
	return (i - ft_lstsize(tmp));
}

int			first_stack(t_list *tmp, int value, int min, int max)
{
	t_list	*t;
	int		i;

	i = 0;
	t = tmp;
	if (value < min || value > max)
	{
		while (t && t->value != min)
		{
			t = t->next;
			i++;
		}
		return (second_stack(tmp, i));
	}
	t->prev = put_last_list(t);
	while (t && !(t->value > value && t->prev->value < value))
	{
		t = t->next;
		i++;
	}
	tmp->prev = NULL;
	return (second_stack(tmp, i));
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int			ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void		find_weights(t_list *tmp1, t_list *tmp2)
{
	t_list	*t1;
	t_list	*t2;
	int		min;
	int		max;
	int		i;


	i = 0;
	t1 = tmp1;
	t2 = tmp2;
	min_max(tmp1, &min, &max);
	while (t2)
	{
		t2->weight_b = second_stack(tmp2, i);
		t2->weight_a = first_stack(t1, t2->value, min, max);
		if (t2->weight_b > 0 && t2->weight_a > 0)
			t2->weight = ft_max(t2->weight_b, t2->weight_a);
		else if (t2->weight_b < 0 && t2->weight_a < 0)
			t2->weight = ft_min(t2->weight_b, t2->weight_a);
		else
			t2->weight = abs(t2->weight_b) + abs(t2->weight_a);
		t2 = t2->next;
		i++;
	}
}

t_list		*min_weight(t_list *tmp2)
{
	t_list	*save;
	t_list	*t2;

	t2 = tmp2;
	save = tmp2;
	while (t2)
	{
		if (t2->weight < save->weight)
			save = t2;
		t2 = t2->next;
	}
	return (save);
}

void		commands_for_weight(t_list **tmp1, t_list **tmp2, t_list *min)
{
	while (min->weight_a > 0 && min->weight_b > 0)
	{
		rotate(tmp1);
		rotate(tmp2);
		min->weight_a--;
		min->weight_b--;
		write(1, "rr\n", 3);
	}
	while (min->weight_a < 0 && min->weight_b < 0)
	{
		reverse_rotate(tmp1);
		reverse_rotate(tmp2);
		min->weight_a++;
		min->weight_b++;
		write(1, "rrr\n", 4);
	}
	while (min->weight_b != 0)
	{
		if (min->weight_b > 0)
		{
			rotate(tmp2);
			min->weight_b--;
			write(1, "rb\n", 3);
		}
		else
		{
			reverse_rotate(tmp2);
			min->weight_b++;
			write(1, "rrb\n", 4);
		}
	}
	while (min->weight_a != 0)
	{
		if (min->weight_a > 0)
		{
			rotate(tmp1);
			min->weight_a--;
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate(tmp1);
			min->weight_a++;
			write(1, "rra\n", 4);
		}
	}
}

void		finish_shift(t_list **tmp)
{
	t_list	*save;
	int		min;
	int		max;
	int		i;

	i = 0;
	save = *tmp;
	min_max(*tmp, &min, &max);
	while (save->value != min)
	{
		save = save->next;
		i++;
	}
	save->weight_a = second_stack(*tmp, i);
	save->weight_b = 0;
	commands_for_weight(tmp, NULL, save);
}

void		swap_5(t_list *tmp1, t_list *tmp2)
{
	t_list	*min;

	push(&tmp2, &tmp1);
	push(&tmp2, &tmp1);
	write(1, "pb\npb\n", 6);
	swap_3(&tmp1);
	while (tmp2)
	{
		min = min_weight(tmp2);
		find_weights(tmp1, tmp2);
		commands_for_weight(&tmp1, &tmp2, min);
		push(&tmp1, &tmp2);
	}
	finish_shift(&tmp1);
	out(tmp1);
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

void		swap_100(t_list *tmp1, t_list *tmp2)
{
	;
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
		swap_3(&tmp1);
	else if (n == 5)
	{
		swap_5(tmp1, tmp2);
	}
	else
		swap_100(tmp1, tmp2);
}