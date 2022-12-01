/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:55:45 by okrich            #+#    #+#             */
/*   Updated: 2022/11/30 18:28:27 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int sn;
	int acc;

	acc = 0;
	sn = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sn = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		acc = acc * 10 + *str - '0';
		str++;
	}
	return (acc * sn);
}

int	cmp(t_list	*lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst;
	while(tmp1)
	{
		tmp2 = tmp1->next;
		while(tmp2)
		{
			if(tmp1->data == tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	pos_min(int	*ar, int size)
{
	int	pos;
	int	min;
	int	ret;

	pos = 0;
	min = ar[pos];
	ret = pos;
	while(pos < size)
	{
		if (min > ar[pos])
		{
			min = ar[pos];
			ret = pos;
		}
		pos++;
	}
	return (ret + 1);
}

int	is_sorted(t_list *a)
{
	while(a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

