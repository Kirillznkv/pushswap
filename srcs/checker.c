/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:48:44 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/06 22:12:55 by kshanti          ###   ########.fr       */
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

int		execute_command(t_list **tmp, char *b)
{
	if (b[0] == 's' && b[1] == 'a' && b[2] == '\n')
		swap(*tmp);
	else if (b[0] == 's' && b[1] == 'b' && b[2] == '\n')
		;//swap(tmp);		2
	else if (b[0] == 's' && b[1] == 's' && b[2] == '\n')
	{
		swap(*tmp);
		;//swap(tmp);		2
	}
	else if (b[0] == 'p' && b[1] == 'a' && b[2] == '\n')
		;//push(tmp);
	else if (b[0] == 'p' && b[1] == 'b' && b[2] == '\n')
		;//push(&tmp, &tmp2);	2
	else if (b[0] == 'r' && b[1] == 'a' && b[2] == '\n')
		rotate(tmp);
	else if (b[0] == 'r' && b[1] == 'b' && b[2] == '\n')
		;//rotate(&tmp2);	2
	else if (b[0] == 'r' && b[1] == 'r' && b[2] == '\n')
	{
		rotate(tmp);
		;//rotate(&tmp2);	2
	}
	else if (b[0] == 'r' && b[1] == 'r' && b[2] == 'a')
		reverse_rotate(tmp);
	else if (b[0] == 'r' && b[1] == 'r' && b[2] == 'b')
		;//reverse_rotate(&tmp2);	2
	else if (b[0] == 'r' && b[1] == 'r' && b[2] == 'r')
	{
		reverse_rotate(tmp);
		;//reverse_rotate(&tmp2);	2
	}
	else
		return (0);
	return (1);
}

int		check_list(t_list *tmp)
{
	t_list		*beg;

	beg = tmp;
	while (beg->next)
	{
		if (beg->value == beg->next->value)
		{
			printf("Error:\nПовторяющиеся аргументы\n");
			exit(1);
		}
		if (beg->value > beg->next->value)
			return (0);
		beg = beg->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_list		*tmp;
	char		*buf;
	int			i;
	int			fl;

	if (argc > 1)
	{
		tmp = init(argv, argc - 1);
		i = -1;
		out(tmp);
		buf = (char*)calloc(4, 1);
		fl = 1;
		while (read(0, &buf[++i], 1) == 1) ///// tmp1 tmp2
		{
			if (i > 3 && fl)
			{////		\n
				printf("Error:\nНеверная команда1\n");
				while (i > -1)
					buf[i--] = '\0';
				fl = 0;
			}
			if (!fl && buf[i] == '\n')
			{
				while (i > -1)
					buf[i--] = '\0';
				fl = 1;
				continue ;
			}
			if (buf[i] == '\n')
			{
				if (!execute_command(&tmp, buf))
					printf("Error:\nНеверная команда2\n");
				out(tmp);
				if (check_list(tmp))
				{
					printf("OK\n");
					exit(0);
				}
				while (i > -1)
					buf[i--] = '\0';
			}
		}
		printf("\nKO\n");
		free(buf);
		free(tmp);
	}
	return (0);
}
