/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:39:10 by kshanti           #+#    #+#             */
/*   Updated: 2022/10/08 02:08:09 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*ft_lstlast(t_stack *lst)
{
	t_stack	*f;

	f = lst;
	if (lst == NULL)
		return (NULL);
	while (f->next != NULL)
		f = f->next;
	return (f);
}
