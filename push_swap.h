/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:56:10 by okrich            #+#    #+#             */
/*   Updated: 2022/11/30 18:28:48 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

void	swap(int *stack, int size, char c);
void	ss(int	*stack_a, int *stack_b, int size_a, int size_b);
void	push(int *src, int *dst, int *size_src, int *size_dst, char c);
void	rotate(int	*stack, int size, char c);
void	reverse_rotate(int *stack, int size, char c);
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);
void	rr(int *stack_a, int *stack_b, int size_a, int size_b);
void	case_of_three(int *ar, int size);
void	case_of_five(int *a, int *b, int size_a, int size_b);
void	case_of_onehundred(int *a, int *b, int size_a, int size_b);

int	ft_atoi(char *str);
int	cmp(t_list *lst);
int	pos_min(int	*ar, int size);
int	is_sorted(t_list *a);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int data);

int	ft_lstsize(t_list *lst);

void	ft_lstadd_front(t_list **lst, t_list *nw);
void	ft_lstadd_back(t_list **lst, t_list *nw);
void	ft_lstclear(t_list **lst);

#endif 
