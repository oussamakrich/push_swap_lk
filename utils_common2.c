/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_common2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:47:56 by okrich            #+#    #+#             */
/*   Updated: 2022/12/09 16:21:08 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexin(t_list **lst, t_list	*nd)
{
	t_list	*tmp;

	tmp = *lst;
	nd->index = 0;
	while (tmp)
	{
		if (tmp->data > nd->data)
			tmp->index += 1;
		else
			nd->index += 1;
		tmp = tmp->next;
	}
}

int	fill_a(char **av, int ac, t_list **a)
{
	char	**str;
	t_list	*node;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		str = ft_split(av[i], ' ');
		if (str == NULL)
			return (1);
		j = 0;
		while (str[j])
		{
			node = ft_lstnew(ft_atoi(str[j], str, a));
			if (node == NULL)
				return (ft_lstclear(a), 1);
			ft_indexin(a, node);
			ft_lstadd_back(a, node);
			j++;
		}
		free_words(str);
	}
	return (0);
}
