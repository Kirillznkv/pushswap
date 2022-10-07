/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:53:35 by kshanti           #+#    #+#             */
/*   Updated: 2022/10/08 00:08:26 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*new_lst;
	t_stack	*pl;

	new_lst = *lst;
	while (new_lst)
	{
		pl = new_lst->next;
		ft_lstdelone(new_lst, del);
		new_lst = pl;
	}
	*lst = NULL;
}
