# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 19:21:23 by aang-shu          #+#    #+#              #
#    Updated: 2024/04/24 17:20:43 by aang-shu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -Wno-unused-variable -I. -g

RM = rm -rf


HELP_DIR = ./helper_utils/
OPER_DIR = ./operations/
SORT_DIR = ./sorting_utils/
HELP_NAMES = ft_atoi.c ft_strdup.c ft_free.c ft_strlen.c ft_putnbr.c \
			lst_util.c ft_putstr_fd.c stack_util.c ft_split.c ft_strcmp.c 
OPER_NAMES = ra_rb_rr.c rotate_operations.c rra_rrb_rrr.c pa_pb.c \
			push_operations.c sa_sb_ss.c swap_operations.c
SORT_NAMES = is_sorted.c number_of_bits.c radix_sort.c sort_small.c 
HELP_SRCS = $(addprefix $(HELP_DIR),$(HELP_NAMES))
OPER_SRCS = $(addprefix $(OPER_DIR),$(OPER_NAMES))
SORT_SRCS = $(addprefix $(SORT_DIR),$(SORT_NAMES))

SRCS = push_swap.c init_utils.c error_check.c $(HELP_SRCS) $(OPER_SRCS) $(SORT_SRCS)

OBJ_DIR = ./obj/
OBJS= $(SRCS:%.c=%.o)

NAME = push_swap

#******************************************************************************#

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean: 
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
