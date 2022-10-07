/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:32:41 by kshanti           #+#    #+#             */
/*   Updated: 2022/10/08 00:09:01 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_stack *lst)
{
	t_stack	*beg;
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
