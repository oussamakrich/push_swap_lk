/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:39:58 by okrich            #+#    #+#             */
/*   Updated: 2022/12/07 17:51:29 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(int index, t_list *lst)
{
	int	i;

	i = 1;
	while (lst)
	{
		if (lst->index == index)
			break ;
		i++;
		lst = lst->next;
	}
	return (i);
}

int	numb_of_instruction(int pos, int size)
{
	int	x;

	if (pos > size / 2)
		x = size - pos + 1;
	else
		x = pos - 1;
	return (x);
}

void	push_back(int index, t_list **src, t_list **dst)
{
	int	pos;
	int	nb_inst;
	int	rtate;

	rtate = 0;
	pos = get_pos(index, *src);
	nb_inst = numb_of_instruction(pos, ft_lstsize(*src));
	if (pos <= ft_lstsize(*src) / 2)
		rtate = 1;
	while (nb_inst)
	{
		if (rtate == 1)
			rotate(src, 'b');
		else
			reverse_rotate(src, 'b');
		nb_inst--;
	}
	push(src, dst, 'a');
}

void	push_two(int first, int second, t_list **src, t_list **dst, int swp)
{
	push_back(first, src, dst);
	push_back(second, src, dst);
	if (swp == 1)
		swap(dst, 'a');
}
