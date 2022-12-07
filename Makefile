# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okrich <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 16:28:30 by okrich            #+#    #+#              #
#    Updated: 2022/12/07 20:05:40 by okrich           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = cc -g

CFLAGS = -Wall -Werror -Wextra

SRC = main ft_push_swap push_swap_cases push_swap_utils \
	  push_swap_utils2 utils_common instruct instruct2 \
	  list_utils list_utils2 ft_printf ft_atoi_utils
	  

SRC_B = checker checker_utils instruct instruct2 \
		list_utils list_utils2 utils_common \
		get_next_line get_next_line_utils ft_printf ft_atoi_utils

OBJ = $(addsuffix .o, $(SRC))

OBJ_B = $(addsuffix .o, $(SRC_B))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_B)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $^

%.o : %.c  push_swap.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all
