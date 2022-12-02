/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:51:30 by okrich            #+#    #+#             */
/*   Updated: 2022/12/02 14:10:57 by okrich           ###   ########.fr       */
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
//
// void	case_of_five(int *a, int *b, int size_a, int size_b)
// {
// 	int	pos;
// 	
// 	while(size_a > 3)
// 	{
// 		pos = pos_min(a, size_a);
// 		if (pos == 2)
// 			swap(a, size_a, 'a');
// 		else if(pos == 3)
// 		{
// 			rotate(a, size_a, 'a');
// 			swap(a, size_a, 'a');
// 		}
// 		else if (pos == 4 && size_a == 5)
// 		{
// 			reverse_rotate(a, size_a, 'a');
// 			reverse_rotate(a, size_a, 'a');
// 		}
// 		else if (pos == 5 || pos == 4)
// 			reverse_rotate(a, size_a, 'a');
// 		push(a, b, &size_a, &size_b, 'b');
// 	}
// 	case_of_three(a, size_a);
// 	push(b, a, &size_b, &size_a, 'a');
// 	push(b, a, &size_b, &size_a, 'a');
// }

void	case_of_five(t_list	**a, t_list **b)
{
	
}


void	case_of_onehundred(int *a, int *b, int size_a, int size_b)
{
		
}







