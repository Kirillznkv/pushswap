/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:06:23 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/06 23:33:27 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
/*-------------------------------structures-----------------------------------*/
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
/*-------------------------------utils----------------------------------------*/
int			equally_str(char *s1, const char *s2);
int			ft_atoi(char *str);
int			ft_isdigit(int c);
/*-------------------------------commands-------------------------------------*/
void		swap(t_list *tmp);
void		push(t_list **t1, t_list **t2);
void		rotate(t_list **tmp);
void		reverse_rotate(t_list **tmp);
/*-------------------------------checker--------------------------------------*/
int			execute_command(t_list **tmp1, t_list **tmp2, char *b);
void		check_list(t_list *tmp1, t_list *tmp2);
int			checkerror(char *buf, int i);
void		checker(t_list *tmp1, t_list *tmp2);

#endif