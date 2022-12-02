/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:55:42 by okrich            #+#    #+#             */
/*   Updated: 2022/12/02 14:02:10 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	isvalid(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (1);
	while(*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (1);
	}
	return (0);
}

void	print_list(t_list **begin_list)
{
	t_list *tmp = *begin_list;
	while(tmp)
	{
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}
}

void my_exit()
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*node;
	int		i;

	i = 0;
	while(++i < ac)
	{
		if (isvalid(av[i]))
			return(write(2, "error", 5), 1);
		// remplir la liste par len num || puis linker le ND entre eux;
	}
	i = 0;
	while(++i < ac)
	{
		node = ft_lstnew(ft_atoi(av[i])); 
		ft_lstadd_back(&a, node);
	}
	// !!!!!pointer being freed was not allocated!!!!
	// if (cmp(a))
	// {
	// 	ft_lstclear(&a);
	// 	return(write(2, "error", 5), 1);
	// }
	// if (is_sorted(a))
	// 	return(ft_lstclear(&a), 0);
	ft_push_swap(&a, &b);
	print_list(&a);	


	// atexit(my_exit);
}
