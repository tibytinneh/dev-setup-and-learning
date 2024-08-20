# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 20:57:06 by aang-shu          #+#    #+#              #
#    Updated: 2024/07/14 10:45:43 by rtanama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#               NAME, compiler, compiler flags, rm, colors
#******************************************************************************#
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
MKDIR = mkdir -p
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#******************************************************************************#
#               Source - paths and filenames
#******************************************************************************#
INCLUDES = -I.

SOURCES = \
    ft_atoi.c \
    ft_itoa.c \
	ft_abs.c \
	ft_abs_double.c \
    ft_toupper.c \
    ft_tolower.c \
	ft_isalnum.c  ft_isascii.c  ft_iscntrl.c  ft_islower.c  ft_isspace.c \
	ft_isxdigit.c ft_isalpha.c  ft_isblank.c  ft_isdigit.c  ft_isprint.c \
	ft_isdigit_str.c \
	ft_isupper.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strlen.c \
	ft_strlcpy.c ft_strcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_substr.c \
	ft_strjoin.c ft_strjoin_free.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_strdup.c \
	ft_strndup.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_strcat.c \
	ft_realloc.c \
	ft_array_len.c \
	get_next_line.c \
	ft_atol.c \
	ft_bubble_sort.c



#******************************************************************************#
#               Object Files
#******************************************************************************#
OBJ_DIR = obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))
#******************************************************************************#
#               Targets
#******************************************************************************#
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN) $(NAME): was created$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(NAME): $(GREEN)$@ was created$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)Object files were deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re

