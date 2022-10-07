/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:52:22 by kshanti           #+#    #+#             */
/*   Updated: 2022/10/08 00:12:25 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(char *argv)
{
	t_stack	*list;

	list = (void *)malloc(sizeof (t_stack));
	if (!list)
		return (NULL);
	list -> argv = ft_strdup(argv);
	if (!list->argv)
		return (NULL);
	list -> next = NULL;
	return (list);
}
