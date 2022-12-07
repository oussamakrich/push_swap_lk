/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:14:10 by okrich            #+#    #+#             */
/*   Updated: 2022/12/07 17:46:05 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	do_instruct(t_list **a, t_list **b, char *inst)
{
	if (ft_strcmp(inst, "sa\n") == 0)
		swap(a, '0');
	else if (ft_strcmp(inst, "sb\n") == 0)
		swap(b, '0');
	else if (ft_strcmp(inst, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(inst, "pa\n") == 0)
		push(b, a, '0');
	else if (ft_strcmp(inst, "pb\n") == 0)
		push(a, b, '0');
	else if (ft_strcmp(inst, "ra\n") == 0)
		rotate(a, '0');
	else if (ft_strcmp(inst, "rb\n") == 0)
		rotate(b, '0');
	else if (ft_strcmp(inst, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(inst, "rra\n") == 0)
		reverse_rotate(a, '0');
	else if (ft_strcmp(inst, "rrb\n") == 0)
		reverse_rotate(b, '0');
	else if (ft_strcmp(inst, "rrr\n") == 0)
		rrr(a, b);
	else
		error(1);
}
