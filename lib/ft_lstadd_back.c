/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:43:06 by kshanti           #+#    #+#             */
/*   Updated: 2022/10/08 00:08:16 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*pl;

	pl = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		if (new)
		{
			while (pl->next)
				pl = pl->next;
			pl->next = new;
		}
	}
}
