/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:51:30 by okrich            #+#    #+#             */
/*   Updated: 2022/12/03 14:49:31 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	case_of_three(t_list **a)
{
	int	n1;
	int	n2;
	int	n3;

	while(is_sorted(*a) == 0)
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
	int	size_a = 5;

	while(size_a > 3)
	{
		pos = pos_min(*a);
		if (pos == 2)
			swap(a, 'a');
		else if(pos == 3)
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
	case_of_three(a);
	push(b, a, 'a');
	push(b, a, 'a');
}


void	case_of_over_five(t_list **a, t_list **b)
{
	// int	min;
	// int	max;
	// int	size;
	// int i = 1;
	//
	// min = 0;
	// max = min + (ft_lstsize(*a) / 5);
	// size = ft_lstsize(*a);
	// while(i <= size || size != 0)
	// {
	// 	int nb = (*a)->data;
	// 	if(nb >= min && nb <= max)
	// 	{
	// 		push(a, b, 'b');
	// 		if (nb >= max / 2)
	// 			rotate(b, 'b');
	// 	}
		// 	else
	// 		rotate(a, 'a');
	// 	size = ft_lstsize(*a);
	// 	i++;
	// }

	int	ref;
	int	i;
	int nb;
	int	moy;
	int	chunk;
	
	if (ft_lstsize(*a) <= 100)
		chunk = ft_lstsize(*a) / 5;
	else
		chunk = ft_lstsize(*a) / 10;
	moy = chunk / 2;
	ref = 0;
	while(*a)
	{
		i = 0;
		ref += chunk;
		while(*a && i < chunk)
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

void	get_b(t_list **a, t_list **b)
{
	int		chunk;
	t_list	*last;
	t_list	*before_last;

	chunk = ft_lstsize(*b);	
	while(--chunk > 0 && ft_lstsize(*b) > 1)
	{
		last = ft_lstlast(*b);
		before_last = ft_before_last(*b);
		if (chunk == (*b)->next->index)
			swap(b, 'b');
		else if (chunk == before_last->index)
		{
			reverse_rotate(b , 'b');
			reverse_rotate(b , 'b');
		}
		else if (chunk == last->index)
			reverse_rotate(b , 'b');
		push(b, a, 'a');
	}
	push(b, a, 'a');
}







