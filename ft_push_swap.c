/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:16:42 by okrich            #+#    #+#             */
/*   Updated: 2022/12/08 16:20:09 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **a, t_list **b)
{
	int	size;
	int	chunk;

	size = ft_lstsize(*a);
	if (size == 2)
		swap(a, 'a');
	else if (size == 3)
		case_of_three(a);
	else if (size == 4)
		case_of_four(a, b);
	else if (size == 5)
	{
		case_of_five(a, b);
		case_of_three(a);
		push(b, a, 'a');
		push(b, a, 'a');
	}
	else if (size > 5)
	{
		chunk = get_chunk(ft_lstsize(*a));
		case_of_over_five(a, b, chunk);
		get_back_b(a, b);
	}
	ft_lstclear(a);
}
