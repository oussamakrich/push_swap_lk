/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:50:29 by okrich            #+#    #+#             */
/*   Updated: 2022/12/09 16:10:48 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	sp_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	sp_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;

	i = sp_strlen(src);
	if (dstsize == 0)
		return (i);
	j = 0;
	while (--dstsize && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
