/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:55:45 by okrich            #+#    #+#             */
/*   Updated: 2022/12/09 16:20:54 by okrich           ###   ########.fr       */
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

int	get_chunk(int size)
{
	if (size < 200)
		return (size / 5);
	else
		return (size / 10);
}
