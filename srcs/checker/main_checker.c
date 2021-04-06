/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:31:16 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/07 00:03:56 by kshanti          ###   ########.fr       */
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
		checker(tmp1, tmp2);
	}
	return (0);
}
