/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:55:45 by okrich            #+#    #+#             */
/*   Updated: 2022/12/04 12:43:38 by okrich           ###   ########.fr       */
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

int	pos_min(t_list	*lst)
{
	int	i;
	int	pos;
	int	min;

	i = 1;
	pos = i;
	min = lst->data;
	lst = lst->next;
	while(lst)
	{
		if (min > lst->data)
		{
			pos = i + 1;
			min = lst->data;
		}
		i++;
		lst = lst->next;
	}
	return(pos);
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

void	ft_indexin(t_list **lst, t_list	*nd)
{
	t_list	*tmp;

	tmp = *lst;
	nd->index = 0;
	while (tmp)
	{
		if (tmp->data > nd->data)
			tmp->index += 1;
		else
			nd->index += 1;
		tmp = tmp->next;
	}
}
