/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:51:30 by okrich            #+#    #+#             */
/*   Updated: 2022/12/08 19:56:43 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_of_three(t_list **a)
{
	int	n1;
	int	n2;
	int	n3;

	while (is_sorted(*a) == 0)
	{
		n1 = (*a)->data;
		n2 = (*a)->next->data;
		n3 = (*a)->next->next->data;
		if (n1 < n2)
			reverse_rotate(a, 'a');
		else if (n1 > n2 && n1 > n3)
			rotate(a, 'a');
		else if (n1 > n2 && n1 < n3)
			swap(a, 'a');
	}
}

void	case_of_four(t_list **a, t_list **b)
{
	int	pos;

	pos = pos_min(*a);
	if (pos == 2)
		swap(a, 'a');
	else if (pos == 3)
	{
		rotate(a, 'a');
		swap(a, 'a');
	}
	else if (pos == 4)
		reverse_rotate(a, 'a');
	push(a, b, 'b');
	case_of_three(a);
	push(b, a, 'a');
}

void	case_of_five(t_list	**a, t_list **b)
{
	int	pos;
	int	size_a;

	size_a = ft_lstsize(*a);
	while (size_a > 3)
	{
		pos = pos_min(*a);
		if (pos == 2)
			swap(a, 'a');
		else if (pos == 3)
		{
			rotate(a, 'a');
			swap(a, 'a');
		}
		else if (pos == 4 && size_a == 5)
		{
			reverse_rotate(a, 'a');
			reverse_rotate(a, 'a');
		}
		else if (pos == 5 || pos == 4)
			reverse_rotate(a, 'a');
		push(a, b, 'b');
		size_a = ft_lstsize(*a);
	}
}

void	case_of_over_five(t_list **a, t_list **b, int chunk)
{
	int	ref;
	int	i;
	int	nb;
	int	moy;

	moy = chunk / 2;
	ref = 0;
	while (*a)
	{
		i = 0;
		ref += chunk;
		while (*a && i < chunk)
		{
			nb = (*a)->index;
			if (nb < ref)
			{
				push(a, b, 'b');
				if (nb >= ref - moy)
					rotate(b, 'b');
				i++;
			}
			else
				rotate(a, 'a');
		}
	}
}

void	get_back_b(t_list **a, t_list **b)
{
	int	index;
	int	pos1;
	int	pos2;
	int	nb_instru_1;
	int	nb_instru_2;

	index = ft_lstsize(*b) - 1;
	while (index > 0)
	{
		pos1 = get_pos(index, *b);
		pos2 = get_pos(index - 1, *b);
		nb_instru_1 = numb_of_instruction(pos1, ft_lstsize(*b));
		nb_instru_2 = numb_of_instruction(pos2, ft_lstsize(*b));
		if (nb_instru_1 > nb_instru_2)
			push_two(b, a);
		else
			push_one(b, a);
		index = ft_lstsize(*b) - 1;
	}
	if (index == 0)
		push(b, a, 'a');
}
