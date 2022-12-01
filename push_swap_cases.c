/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:51:30 by okrich            #+#    #+#             */
/*   Updated: 2022/11/30 11:28:44 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	case_of_three(int *ar, int size)
{
	while(is_sorted(ar, size) == 0)
	{
		if (ar[0] < ar[1])
			reverse_rotate(ar, size, 'a');
		else if (ar[0] > ar[1] && ar[0] > ar[2])
			rotate(ar, size, 'a');	
		else if (ar[0] > ar[1] && ar[0] < ar[2])	
			swap(ar, size, 'a');
	}
}

void	case_of_five(int *a, int *b, int size_a, int size_b)
{
	int	pos;
	
	while(size_a > 3)
	{
		pos = pos_min(a, size_a);
		if (pos == 2)
			swap(a, size_a, 'a');
		else if(pos == 3)
		{
			rotate(a, size_a, 'a');
			swap(a, size_a, 'a');
		}
		else if (pos == 4 && size_a == 5)
		{
			reverse_rotate(a, size_a, 'a');
			reverse_rotate(a, size_a, 'a');
		}
		else if (pos == 5 || pos == 4)
			reverse_rotate(a, size_a, 'a');
		push(a, b, &size_a, &size_b, 'b');
	}
	case_of_three(a, size_a);
	push(b, a, &size_b, &size_a, 'a');
	push(b, a, &size_b, &size_a, 'a');
}

void	case_of_onehundred(int *a, int *b, int size_a, int size_b)
{
		
}







