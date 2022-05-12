/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:06:23 by kshanti           #+#    #+#             */
/*   Updated: 2022/05/13 01:50:31 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"//del
# include "stdlib.h"
# include "unistd.h"
# include "math.h"///////////
///////////////
// Убрать abs
// Проверить надобность дублируешего адреса листа
// Написать проверку на одинаковые значения
///////////////
/*-------------------------------structures-----------------------------------*/
typedef struct		s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_node
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_node;
/*-------------------------------commands-------------------------------------*/
void		sa(t_node *node);
void		sb(t_node *node);
void		ss(t_node *node);
void		pa(t_node *node);
void		pb(t_node *node);
void		ra(t_node *node);
void		rb(t_node *node);
void		rr(t_node *node);
void		rra(t_node *node);
void		rrb(t_node *node);
void		rrr(t_node *node);
/*-------------------------------command_utils--------------------------------*/
void		swap(t_stack *stack);
void		push(t_stack **stack_in, t_stack **stack_out);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
/*-------------------------------base_utils-----------------------------------*/
int			ft_atoi(char *str);
size_t		ft_strlen(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
/*-------------------------------parse_utils----------------------------------*/
int			ft_isdigit(int c);
int			is_valid_elem(char *str);
void		add_elem(t_stack **tmp, int elem);
/*-------------------------------checkers-------------------------------------*/
int			is_sorted(t_node *stacks);
/*-------------------------------sort-----------------------------------------*/
void		ft_sort(t_node *stacks, int n);
void		sort_3(t_node *stacks);
void		sort_5(t_node *stacks);
void		mega_sort(t_node *stacks);

#endif