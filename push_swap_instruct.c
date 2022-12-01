/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:55:43 by okrich            #+#    #+#             */
/*   Updated: 2022/11/26 19:40:08 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	swap(int *stack, int size, char c)
{
	int	tmp;

	if (size <= 1)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (c != '0')
		ft_printf("s%c\n",c);
}

void	ss(int	*stack_a, int *stack_b, int size_a, int size_b)
{
	swap(stack_a, size_a, '0');
	swap(stack_b, size_b, '0');
	ft_printf("ss\n");

}

void	push(int *src, int *dst, int *size_src, int *size_dst, char c)
{
	int tmp;
	int i;

	if (*size_src == 0)
		return ;
	tmp = src[0];
	i = -1;
	while(++i < *size_src - 1)
		src[i] = src[i + 1];
	i = *size_dst + 1;
	while(--i > 0)
		dst[i] = dst[i - 1];
	dst[0] = tmp;
	*size_src -= 1;
	*size_dst += 1;
	if (c != '0')
		ft_printf("p%c\n",c);
}

void	rotate(int	*stack, int size, char c)
{
	int	tmp;
	int	i;
	
	if (size == 1)
		return ;
	tmp = stack[0];
	i = -1;
	while(++i < size - 1)
		stack[i] = stack[i + 1];
	stack[i] = tmp;
	if (c != '0')
		ft_printf("r%c\n",c);
}

void	reverse_rotate(int *stack, int size, char c)
{
	int	tmp;
	int	i;

	tmp = stack[size - 1]; 
	i = size;
	while(--i > 0)
		stack[i] = stack[i - 1];
	stack[0] = tmp;
	if (c != '0')
		ft_printf("rr%c\n",c);
}

void	rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rotate(stack_a, size_a, '0');
	rotate(stack_b, size_b, '0');
	ft_printf("rr\n");
}

void	rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	reverse_rotate(stack_a, size_a, '0');
	reverse_rotate(stack_b, size_b, '0');
	ft_printf("rrr\n");
}
