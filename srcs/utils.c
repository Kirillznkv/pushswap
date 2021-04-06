/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:41:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/06 23:27:07 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int					ft_atoi(char *str)
{
	unsigned int	res;
	unsigned int	i;
	char			m;

	m = 0;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
		str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m++;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9' && res < __INT32_MAX__)
		res = res * 10 + str[i++] - '0';
	if (res > __INT32_MAX__)
		res = __INT32_MAX__;
	return (m ? -res : res);
}

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			equally_str(char *s1, const char *s2)
{
	if (s1 && s2)
	{
		while (*s1 == *s2 && *s1 != '\0')
		{
			s1++;
			s2++;
		}
		if (*s1 == *s2)
			return (1);
	}
	return (0);
}
