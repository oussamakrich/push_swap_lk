/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:22 by okrich            #+#    #+#             */
/*   Updated: 2022/12/09 16:19:55 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_res_clean(t_list **a, t_list **b, int size_b)
{
	if (is_sorted(*a) && size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(a);
	ft_lstclear(b);
}

void	read_instruct(t_list **a, t_list **b)
{
	char	*instruct;

	instruct = get_next_line(0);
	while (instruct)
	{
		do_instruct(a, b, instruct);
		free(instruct);
		instruct = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**str;
	int		i;

	if (ac == 1)
		return (0);
	i = 0;
	while (av[++i])
	{
		str = ft_split(av[i], ' ');
		if (str == NULL)
			return (1);
		isvalid(str);
		free_words(str);
	}
	if (fill_a(av, ac, &a))
		return (1);
	cmp(&a);
	read_instruct(&a, &b);
	print_res_clean(&a, &b, ft_lstsize(b));
}
