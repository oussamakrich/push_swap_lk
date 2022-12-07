/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrich <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:56 by okrich            #+#    #+#             */
/*   Updated: 2022/12/07 10:35:37 by okrich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H 

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
# include <sys/_types/_ssize_t.h>
# include <sys/fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strnjoin(char *s1, char *s2, ssize_t i);
char	*ft_strndup(char *s1, ssize_t n);
char	*get_next_line(int fd);
ssize_t	ft_strlen(char *str);
# include <stdio.h>
# include <unistd.h>


#endif

