# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 18:29:41 by aang-shu          #+#    #+#              #
#    Updated: 2024/07/03 17:15:33 by rtanama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#               NAME, compiler, compiler flags, rm
#******************************************************************************#
NAME = minishell
TEST_NAME = minishell_test
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
AR = ar rcs
MKDIR = mkdir -p
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

#******************************************************************************#
#               Library
#******************************************************************************#
LIBFT_NAME = libft.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)
LIBFT_FLAGS = -L./libft -lft

# Specify readline flags and libraries
READLINE_FLAGS = -I/usr/include/readline
READLINE_LIBS = -lreadline -lhistory

#******************************************************************************#
#               Source - paths and filenames
#******************************************************************************#
INCLUDES = -Iincludes -I$(LIBFT_DIR) $(READLINE_FLAGS)

SRCS_DIR = srcs
UTILS_DIR = utils
BUILTIN_DIR = builtins
LEXER_DIR = lexer
AST_DIR = ast

SRCS_NAMES = main.c main_utils.c
UTILS_NAMES = get_cmd_args.c execute_builtin_cmd.c process_input.c signal_init_handler.c \
			env_handler.c execute_external_cmd.c path_handler.c process_input_handler.c \
			pipe_handler.c redirection_out_handler.c redirection_in_handler.c error_handler.c \
			env_expand_handler.c heredoc_handler.c heredoc_handler_utils.c heredoc_child_handler.c append_handler.c \
			path_handler_utils.c signal_init_handler_utils.c
BUILTIN_NAMES = echo.c pwd.c env.c exit.c clear.c cd.c export.c unset.c export_utils.c
LEXER_NAMES = lexer.c lexer_utils.c lexer_handler.c lexer_paren.c
AST_NAMES = ast.c parser.c parser_utils.c parser_token_utils.c parser_check.c parser_stack.c parser_queue.c \
			parser_processor.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))
UTILS = $(addprefix $(UTILS_DIR)/, $(UTILS_NAMES))
BUILTINS = $(addprefix $(BUILTIN_DIR)/, $(BUILTIN_NAMES))
LEXERS = $(addprefix $(LEXER_DIR)/, $(LEXER_NAMES))
ASTS = $(addprefix $(AST_DIR)/, $(AST_NAMES))

#******************************************************************************#
#               Object Files, dependencies
#******************************************************************************#
OBJ_DIR = obj
SRCS_OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS_NAMES))
UTILS_OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(UTILS_NAMES))
BUILTINS_OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(BUILTIN_NAMES))
LEXERS_OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LEXER_NAMES))
ASTS_OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(AST_NAMES))
OBJS = $(SRCS_OBJS) $(UTILS_OBJS) $(BUILTINS_OBJS) $(LEXERS_OBJS) $(ASTS_OBJS)
DEPS = $(OBJS:.o=.d)

#******************************************************************************#
#               Tests
#******************************************************************************#
TEST_DIR = tests
TEST_NAMES = lexer.test.c main.test.c parser.test.c
TEST_SRCS = $(addprefix $(TEST_DIR)/, $(TEST_NAMES))
TEST_OBJS = $(TEST_SRCS:.c=.o) $(LEXERS_OBJS) $(ASTS_OBJS) $(UTILS_OBJS) $(BUILTINS_OBJS)
TEST_DEPS = $(TEST_OBJS:.o=.d)

#******************************************************************************#
#               Targets
#******************************************************************************#
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking object files to create $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(READLINE_LIBS) -o $(NAME)
	@echo "$(GREEN)Build successful!$(RESET)"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJ_DIR)/%.o: $(BUILTIN_DIR)/%.c | $(OBJ_DIR)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJ_DIR)/%.o: $(LEXER_DIR)/%.c | $(OBJ_DIR)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJ_DIR)/%.o: $(AST_DIR)/%.c | $(OBJ_DIR)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJ_DIR):
	@echo "$(CYAN)Making object directory$(RESET)"
	@$(MKDIR) $(OBJ_DIR)

$(LIBFT):
	@echo "$(MAGENTA)Compiling Libft$(RESET)"
	@make -C $(LIBFT_DIR)

clean:
	@echo "$(RED)Cleaning up object files and dependencies$(RESET)"
	@$(RM) $(OBJS) $(DEPS) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Cleaning up executable and library files$(RESET)"
	@$(RM) $(NAME) $(LIBFT)

re: fclean all

valgrind:
	valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all ./minishell

valgrind_env:
	valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all env -i ./minishell

valgrind_track:
	valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes ./minishell

clean_test:
	@echo "$(RED)Cleaning up test files$(RESET)"
	@$(RM) $(TEST_OBJS) $(TEST_DEPS) $(TEST_NAME)

test: $(TEST_NAME)
	@echo "$(GREEN)Running test:$(RESET)"
	@./$(TEST_NAME)
	@make clean_test

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@echo "$(BLUE)Compiling test $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -I$(TEST_DIR) -MMD -c $< -o $@

$(TEST_NAME): $(TEST_OBJS)
	@echo "$(MAGENTA)Creating test executable $@$(RESET)"
	@$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBFT_FLAGS) $(READLINE_LIBS) -o $(TEST_NAME)

-include $(DEPS) $(TEST_DEPS)
.PHONY: all clean fclean re test clean_test
