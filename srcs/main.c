/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:48:44 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/06 14:00:19 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	out(t_list *tmp)
{
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	t_list		*tmp;
	if (argc > 1)
	{
		tmp = init(argv, argc - 1);
		out(tmp);
		reverse_rotate(&tmp);
		out(tmp);
		free(tmp);
	}
	return (0);
}
