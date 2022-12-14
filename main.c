/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:55:42 by okrich            #+#    #+#             */
/*   Updated: 2022/12/09 16:11:45 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**str;
	int		i;

	i = 0;
	if (ac == 1)
		return (0);
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
	if (is_sorted(a) == 1)
		return (ft_lstclear(&a), 0);
	ft_push_swap(&a, &b);
}
