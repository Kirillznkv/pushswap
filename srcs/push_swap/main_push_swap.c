/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:59:49 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/07 00:36:27 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int		main(int argc, char **argv)
{
	t_list		*tmp1;
	t_list		*tmp2;

	if (argc > 1)
	{
		tmp1 = init(argv, argc - 1);
		tmp2 = NULL;
		push_swap(tmp1, tmp2, argc - 1);
	}
	return (0);
}