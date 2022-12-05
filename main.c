/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:55:42 by okrich            #+#    #+#             */
/*   Updated: 2022/12/05 19:01:45 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int ret)
{
	write(2, "Error", 5);
	exit (ret);
}

void	isvalid(char **av)
{
	char	*str;
	int		i;

	i = 1;
	while (av[i])
	{
		str = av[i];
		if (*str == '-' || *str == '+')
			str++;
		if (*str == '\0')
			error(1);
		while (*str)
		{
			if (*str >= '0' && *str <= '9')
				str++;
			else
				error(1);
		}
		i++;
	}
}

void	print_list(t_list *tmp)
{
	while (tmp)
	{
		printf("data = %d index = %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
}

// void my_exit()
// {
// 	system("leaks push_swap");
// }
//
int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*node;
	int		i;

	i = 0;
	// FIX : CHECK OVERFLOW
	isvalid(av);
	while (++i < ac)
	{
		node = ft_lstnew(ft_atoi(av[i]));
		if (node == NULL)
			return (ft_lstclear(&a), 1);
		ft_indexin(&a, node);
		ft_lstadd_back(&a, node);
	}
	if (cmp(a))
	{
		ft_lstclear(&a);
		error(1);
	}
	if (is_sorted(a))
		return (ft_lstclear(&a), 0);
	ft_push_swap(&a, &b);
}
