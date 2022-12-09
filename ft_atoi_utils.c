/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:04:37 by okrich            #+#    #+#             */
/*   Updated: 2022/12/09 15:16:05 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_sn(char *str, int *sn)
{
	*sn = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sn = -1;
		str++;
	}
	return (str);
}

int	ft_atoi(char *str, char **sp, t_list **a)
{
	int	sn;
	int	res;
	int	acc;

	acc = 0;
	res = 0;
	str = get_sn(str, &sn);
	while (*str >= '0' && *str <= '9')
	{
		res = acc * 10 + *str - '0';
		str++;
		if (res == -2147483648 && sn == -1 && *str == '\0')
			return (-2147483648);
		if (res < acc)
		{
			ft_lstclear(a);
			free_words(sp);
			error(1);
		}
		acc = res;
	}
	return (acc * sn);
}
