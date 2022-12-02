/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:51:30 by okrich            #+#    #+#             */
/*   Updated: 2022/12/02 17:27:26 by okrich           ###   ########.fr       */
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


void	case_of_onehundred(int *a, int *b, int size_a, int size_b)
{
				
}







