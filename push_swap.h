/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:06:23 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/05 22:50:35 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "stdlib.h"

typedef struct		s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

/*-------------------------------list-----------------------------------------*/
void		add_back(t_list **lst, t_list *new);
void		add_front(t_list **lst, t_list *new);
t_list		*lstnew(int value);
int			lstsize(t_list *lst);
/*-------------------------------utils----------------------------------------*/
int			nicelst(char *str, int *value);
t_list		*init(char **argv, int n);

#endif