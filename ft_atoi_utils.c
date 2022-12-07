/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:04:37 by okrich            #+#    #+#             */
/*   Updated: 2022/12/07 20:05:01 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	skip_spaces(char **dub)
{
	char	*str;

	str = *dub;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
}

int	get_sn(char **dub)
{
	char	*str;
	int		sn;

	str = *dub;
	sn = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sn = -1;
		str++;
	}
	return (sn);
}

int	ft_atoi(char *str, t_list **a)
{
	int	sn;
	int	res;
	int	acc;

	acc = 0;
	res = 0;
	skip_spaces(&str);
	sn = get_sn(&str);
	while (*str >= '0' && *str <= '9')
	{
		res = acc * 10 + *str - '0';
		str++;
		if (res == -2147483648 && sn == -1 && *str == '\0')
			return (-2147483648);
		if (res < acc)
		{
			ft_lstclear(a);
			error(1);
		}
		acc = res;
	}
	return (acc * sn);
}
