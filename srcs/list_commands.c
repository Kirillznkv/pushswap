/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:13:17 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/07 23:30:53 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		add_back(t_list **lst, t_list *new)
{
	t_list	*pl;

	pl = *lst;
	if (*lst == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
	}
	else if (new)
	{
		while (pl->next)
			pl = pl->next;
		pl->next = new;
		new->next = NULL;
		new->prev = pl;
	}
}

void		add_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		if (new)
		{
			new->prev = NULL;
			new->next = *lst;
			(*lst)->prev = new;
		}
		*lst = new;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
	}
}

t_list		*lstnew(int value)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->value = value;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_list		*put_last_list(t_list *tmp)
{
	t_list	*p;

	p = tmp;
	while (p && p->next)
		p = p->next;
	return (p);
}
