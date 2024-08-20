/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:23:53 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 06:10:29 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# include "minishell.h"

/* -------------------------------------------------------------------------- */
/*                                 MAIN SHELL                                 */
/* -------------------------------------------------------------------------- */
typedef struct s_shell
{
	char	**envp;
	char	*cwd[PATH_MAX];
	char	*username;
	char	*input_str;
	char	*input_buf;
	int		input_check;
}			t_shell;

/* -------------------------------------------------------------------------- */
/*                                   TOKENS                                   */
/* -------------------------------------------------------------------------- */
typedef enum e_token_type
{
	TOKEN_ARGUMENT,
	TOKEN_LITERAL,
	TOKEN_REDIRECTION,
	TOKEN_PIPE,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_OPEN_PAREN,
	TOKEN_CLOSE_PAREN,
	TOKEN_EOF
}				t_token_type;

typedef struct s_token
{
	t_token_type	type;
	int				position;
	char			*content;
	struct s_token	*next;
}				t_token;

/* -------------------------------------------------------------------------- */
/*                                     AST                                    */
/* -------------------------------------------------------------------------- */
typedef enum s_node_type
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_REDIRECT_IN,
	NODE_REDIRECT_OUT,
	NODE_REDIRECT_APPEND,
	NODE_REDIRECT_HEREDOC,
	NODE_AND,
	NODE_OR,
	NODE_OPEN_PAREN,
	NODE_CLOSE_PAREN,
}	t_node_type;

typedef struct s_ast_node
{
	t_node_type			type;
	char				**args;
	char				*filename;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;

/* -------------------------------------------------------------------------- */
/*                                    STACK                                   */
/* -------------------------------------------------------------------------- */
typedef struct s_stack_node
{
	t_ast_node			*value;
	struct s_stack_node	*next;
}			t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	size_t			size;
}			t_stack;

/* -------------------------------------------------------------------------- */
/*                                    QUEUE                                   */
/* -------------------------------------------------------------------------- */
typedef struct s_queue_node
{
	t_ast_node			*value;
	struct s_queue_node	*next;
}	t_queue_node;

typedef struct s_queue
{
	t_queue_node	*front;
	t_queue_node	*rear;
	size_t			size;
}	t_queue;

/* -------------------------------------------------------------------------- */
/*                                    PIPE                                    */
/* -------------------------------------------------------------------------- */
typedef struct s_pipe
{
	int		pipe_fd[2];
}			t_pipe;

#endif
