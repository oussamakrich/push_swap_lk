/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:56:10 by okrich            #+#    #+#             */
/*   Updated: 2022/12/04 13:43:26 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

void	ft_putstr(char *str, int *count);
int		ft_printf(const char *s, ...);

void	case_of_three(t_list **a);
void	case_of_four(t_list **a, t_list **b);
void	case_of_five(t_list	**a, t_list **b);
void	case_of_over_five(t_list **a, t_list **b);
void	get_b(t_list **a, t_list **b);
void	get_back_b(t_list **a, t_list **b);

void	ft_push_swap(t_list **a, t_list **b);
void	swap(t_list	**a, char c);
void	ss(t_list **a, t_list **b);
void	push(t_list	**src, t_list **dst, char c);
void	rotate(t_list **lst, char c);
void	rr(t_list **a, t_list **b);
void	reverse_rotate(t_list **lst, char c);
void	rrr(t_list **a, t_list **b);

int	numb_of_instruction(int	pos, int size);
int	pos_min(t_list	*lst);
int	ft_atoi(char *str);
int	is_sorted(t_list *a);
int	cmp(t_list *lst);
int	get_pos(int	index, t_list *lst);

void	push_back(int index, t_list **src, t_list **dst);	

t_list	*ft_before_last(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int data);

int	ft_lstsize(t_list *lst);

void	ft_lstadd_front(t_list **lst, t_list *nw);
void	ft_lstadd_back(t_list **lst, t_list *nw);
void	ft_lstclear(t_list **lst);
void	ft_indexin(t_list **lst, t_list	*nd);

#endif 
