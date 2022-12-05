# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okrich <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 16:28:30 by okrich            #+#    #+#              #
#    Updated: 2022/12/05 18:07:59 by okrich           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc -g

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf ft_push_swap main list_utils2 \
	  push_swap_instruct push_swap_utils \
	  push_swap_utils2 push_swap_cases list_utils

OBJ = $(addsuffix .o, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^
%.o : %.c  push_swap.h 
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
