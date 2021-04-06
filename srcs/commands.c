/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:30:37 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/06 13:58:47 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		swap(t_list *tmp)
{
	int		save;

	if (tmp && tmp->next)
	{
		save = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = save;
	}
}

void		push(t_list **t1, t_list **t2)
{
	t_list	*save;

	if (*t2)
	{
		save = *t2;
		*t2 = (*t2)->next;
		if (*t2)
			(*t2)->prev = NULL;
		add_front(t1, save);
	}
}

void		rotate(t_list **tmp)
{
	t_list	*save;

	if (*tmp && (*tmp)->next)
	{
		save = *tmp;
		*tmp = (*tmp)->next;
		(*tmp)->prev = NULL;
		add_back(tmp, save);
	}
}

void		reverse_rotate(t_list **tmp)
{
	t_list	*save;
	t_list	*beg;

	if (*tmp && (*tmp)->next)
	{
		beg = *tmp;
		while (beg->next->next)
			beg = beg->next;
		save = beg->next;
		beg->next = NULL;
		add_front(tmp, save);
	}
}
