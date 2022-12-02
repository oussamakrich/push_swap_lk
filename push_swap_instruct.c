/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:55:43 by okrich            #+#    #+#             */
/*   Updated: 2022/12/02 13:36:00 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

void	swap(t_list	**lst, char c)
{
	int	tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = tmp;
	if (c != '0')
		ft_printf("s%c\n",c);
}

void	ss(t_list **a, t_list **b)
{
	swap(a, '0');
	swap(b, '0');
	ft_printf("ss\n");

}

void	push(t_list	**src, t_list **dst, char c)
{	
	void	*tmp;

	tmp = (*src)->next;
	ft_lstadd_front(dst , *src);
	*src = tmp;
	if (c != '0')
		ft_printf("p%c\n",c);
}

void	rotate(t_list **lst, char c)
{
	t_list	*tmp;

	if ((*lst)->next == NULL)
		return ;
	tmp = *lst;
	ft_lstadd_back(lst, *lst);	
	*lst = (*lst)->next;
	tmp->next = NULL;
	if (c != '0')
		ft_printf("r%c\n",c);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a, '0');
	rotate(b, '0');
	ft_printf("rr\n");
}

void	reverse_rotate(t_list **lst, char c)
{
	t_list	*last;
	t_list	*beforelast;

	if ((*lst)->next == NULL)
		return ;
	beforelast = ft_before_last(*lst);
	last = ft_lstlast(*lst);
	ft_lstadd_front(lst, last);
	beforelast->next = NULL;
	if (c != '0')
		ft_printf("rr%c\n",c);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a, '0');
	reverse_rotate(b, '0');
	ft_printf("rrr\n");
}
