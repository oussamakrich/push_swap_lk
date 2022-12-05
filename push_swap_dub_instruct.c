/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dub_instruct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:09:41 by okrich            #+#    #+#             */
/*   Updated: 2022/12/05 16:10:14 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a, t_list **b)
{
	rotate(a, '0');
	rotate(b, '0');
	ft_printf("rr\n");
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a, '0');
	reverse_rotate(b, '0');
	ft_printf("rrr\n");
}
