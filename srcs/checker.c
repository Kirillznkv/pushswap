/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:48:44 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/06 23:17:42 by kshanti          ###   ########.fr       */
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

int		execute_command(t_list **tmp1, t_list **tmp2, char *b)
{
	if (equally_str(b, "sa\n"))
		swap(*tmp1);
	else if (equally_str(b, "sb\n"))
		swap(*tmp2);
	else if (equally_str(b, "ss\n"))
	{
		swap(*tmp1);
		swap(*tmp2);
	}
	else if (equally_str(b, "pa\n"))
		push(tmp1, tmp2);
	else if (equally_str(b, "pb\n"))
		push(tmp2, tmp1);
	else if (equally_str(b, "ra\n"))
		rotate(tmp1);
	else if (equally_str(b, "rb\n"))
		rotate(tmp2);
	else if (equally_str(b, "rr\n"))
	{
		rotate(tmp1);
		rotate(tmp2);
	}
	else if (equally_str(b, "rra\n"))
		reverse_rotate(tmp1);
	else if (equally_str(b, "rrb\n"))
		reverse_rotate(tmp2);
	else if (equally_str(b, "rrr\n"))
	{
		reverse_rotate(tmp1);
		reverse_rotate(tmp2);
	}
	else
		return (0);
	return (1);
}

void		check_list(t_list *tmp1, t_list *tmp2)
{
	t_list		*beg;

	beg = tmp1;
	while (beg && beg->next)
	{
		if (beg->value == beg->next->value)
		{
			printf("Error:\nПовторяющиеся аргументы\n");
			exit(1);
		}
		if (beg->value > beg->next->value)
			return ;
		beg = beg->next;
	}
	if (tmp2 == NULL)
	{
		printf("OK\n");
		exit(0);
	}
}

int		checkerror(char *buf, int i)
{
	if (i > 3)
	{
		printf("Error:\nНеверная команда\n");
		while (i > -1)
			buf[i--] = '\0';
		while (read(0, &buf[0], 1) == 1 && buf[0] != '\n')
			;
	}
	return (i);
}

void	checker(t_list *tmp1, t_list *tmp2)
{
	char	*buf;
	int		i;

	i = -1;
	buf = (char*)calloc(5, 1);
	check_list(tmp1, tmp2);
	while (read(0, &buf[++i], 1) == 1)
	{
		i = checkerror(buf, i);
		if (buf[i] == '\n')
		{
			if (!execute_command(&tmp1, &tmp2, buf))
				printf("Error:\nНеверная команда\n");
			check_list(tmp1, tmp2);
			printf("--->a: ");
			out(tmp1);
			printf("--->b: ");
			out(tmp2);
			while (i > -1)
				buf[i--] = '\0';
		}
	}
	printf("\nKO\n");
	free(buf);
	free(tmp1);
}

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
