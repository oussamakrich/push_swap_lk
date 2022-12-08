/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:55:42 by okrich            #+#    #+#             */
/*   Updated: 2022/12/08 16:48:25 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// void my_exit()
// {
// 	system("leaks push_swap");
// }

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*node;
	int		i;

	i = 0;
	isvalid(av);
	while (++i < ac)
	{
		node = ft_lstnew(ft_atoi(av[i], &a));
		if (node == NULL)
			return (ft_lstclear(&a), 1);
		ft_indexin(&a, node);
		ft_lstadd_back(&a, node);
	}
	cmp(&a);
	if (is_sorted(a))
		return (ft_lstclear(&a), 0);
	ft_push_swap(&a, &b);
	// atexit(my_exit);
}
