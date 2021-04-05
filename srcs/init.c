/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:31:16 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/05 22:52:21 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list		*init(char **argv, int n)
{
	int		i;
	int		value;
	t_list	*tmp;

	i = 0;
	tmp = NULL;
	while (++i <= n)
	{
		if (!nicelst(argv[i], &value))
		{
			printf("Error:\nНеверный аргумент\n");
			exit(1);
		}
		add_back(&tmp, lstnew(value));
	}
	return (tmp);
}
