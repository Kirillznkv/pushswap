/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:41:21 by kshanti           #+#    #+#             */
/*   Updated: 2021/04/05 22:52:03 by kshanti          ###   ########.fr       */
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

int			nicelst(char *str, int *value)
{
	int		i;
	int		dig;

	i = 0;
	dig = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		dig++;
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0' || !dig)
		return (0);
	*value = ft_atoi(str);
	return (1);
}