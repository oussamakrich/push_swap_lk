/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:01:12 by okrich            #+#    #+#             */
/*   Updated: 2022/12/02 13:47:06 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*ptr;

	if (*lst == NULL)
		*lst = nw;
	else
	{
		ptr = ft_lstlast(*lst);
		ptr->next = nw;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *nw)
{
	nw->next = *lst;
	*lst = nw;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstnew(int data)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}


t_list	*ft_before_last(t_list *lst)
{
	while (lst->next)
	{
		if (lst->next->next == NULL)
			break ;
		lst = lst->next;
	}	
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}	
	return (lst);
}
void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(lst);
		*lst = tmp;
		// for debug 
		printf("free\n");
	}
}
