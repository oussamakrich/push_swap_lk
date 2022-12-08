/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:30:50 by okrich            #+#    #+#             */
/*   Updated: 2022/12/07 21:14:47 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int ret)
{
	write(2, "Error\n", 6);
	exit (ret);
}

void	isvalid(char **av)
{
	char	*str;
	int		i;

	i = 1;
	while (av[i])
	{
		str = av[i];
		if (*str == '-' || *str == '+')
			str++;
		if (*str == '\0')
			error(1);
		while (*str)
		{
			if (*str >= '0' && *str <= '9')
				str++;
			else
				error(1);
		}
		i++;
	}
}

void	cmp(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data == tmp2->data)
			{
				ft_lstclear(a);
				error(1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}
