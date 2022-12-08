/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:55:45 by okrich            #+#    #+#             */
/*   Updated: 2022/12/08 17:33:12 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_min(t_list	*lst)
{
	int	i;
	int	pos;
	int	min;

	i = 1;
	pos = i;
	min = lst->data;
	lst = lst->next;
	while (lst)
	{
		i++;
		if (min > lst->data)
		{
			pos = i;
			min = lst->data;
		}
		lst = lst->next;
	}
	return (pos);
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

int	get_chunk(int size)
{
	if (size < 200)
		return (size / 5);
	else
		return (size / 10);
}
