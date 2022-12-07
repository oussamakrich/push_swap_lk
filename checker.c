/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:22 by okrich            #+#    #+#             */
/*   Updated: 2022/12/07 18:51:15 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_res_clean(t_list **a, int size_b)
{
	if (is_sorted(*a) && size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(a);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*node;
	char	*instruct;
	int		i;

	if (ac == 1)
		return (0);
	isvalid(av);
	i = 0;
	while (++i < ac)
	{
		node = ft_lstnew(ft_atoi(av[i], &a));
		if (node == NULL)
			return (ft_lstclear(&a), 1);
		ft_lstadd_back(&a, node);
	}
	cmp(&a);
	instruct = get_next_line(0);
	while (instruct)
	{
		do_instruct(&a, &b, instruct);
		instruct = get_next_line(0);
	}
	print_res_clean(&a, ft_lstsize(b));
}
