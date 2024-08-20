/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:15:22 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/14 10:57:27 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FUNCTIONS_H
# define MINISHELL_FUNCTIONS_H

# include "minishell.h"

/* -------------------------------------------------------------------------- */
/*                                   SIGNALS                                  */
/* -------------------------------------------------------------------------- */
void			init_signal_hook(void);
void			sigquit_handler(int signum);
void			sigint_handler(int signum);
void			child_sigint_handler(int signum);
void			child_sigint_handler_external(int signum);
void			disable_ctrl_backslash_echo(void);
void			enable_ctrl_backslash_echo(void);

/* -------------------------------------------------------------------------- */
/*                               INITIALIZATION                               */
/* -------------------------------------------------------------------------- */
int				init_shell(t_shell *data, char **envp);
char			*get_prompt(void);
char			*replace_home_with_tilde(const char *cwd, const char *home);

/* -------------------------------------------------------------------------- */
/*                                  CLEAN UP                                  */
/* -------------------------------------------------------------------------- */
void			free_array_of_strings(char **strs);

/* -------------------------------------------------------------------------- */
/*                                 ENVIRONMENT                                */
/* -------------------------------------------------------------------------- */
/* --------------------------- ENVIRONMENT - ENVP --------------------------- */
int				find_env_var(char **envp, const char *var);
int				update_shlvl(char ***envp);
int				append_env_var(char ***envp, char *new_var);
char			*envp_shlvl(char **envp);
char			**envp_copy(char **envp);

/* -------------------------- ENVIRONMENT - Execve -------------------------- */
char			*extract_pathvar(char **envp);
char			*append_path(char *path, char *cmd);
char			*extract_abs_path(char *cmd, char **envp);
int				get_path_validity(char *path);
void			handle_child_sigquit(int signum);
int				execute_external_cmd(char *command, char **args,
					t_shell *data);

/* -------------------------------------------------------------------------- */
/*                                    INPUT                                   */
/* -------------------------------------------------------------------------- */
/* ------------------------------ INPUT - Init ------------------------------ */
int				take_input(t_shell *data);

/* --------------------------- INPUT - Processing --------------------------- */
int				execute_cmd(t_ast_node *node, t_shell *data);
char			**get_cmd_args(t_token *tokens);
int				process_input(t_shell *data);

/* ----------------------------- INPUT - Handler ---------------------------- */
int				handle_and(t_ast_node *node, t_shell *data);
int				handle_or(t_ast_node *node, t_shell *data);
int				handle_pipe(t_ast_node *node, t_shell *data);
int				handle_redirection_out(t_ast_node *node, t_shell *data);
int				handle_redirection_in(t_ast_node *node, t_shell *data);
/* --------------------------------- HEREDOC -------------------------------- */
int				handle_heredoc(t_ast_node *node, t_shell *data);
int				handle_error_heredoc(int fd[2]);
void			handle_cleanup_heredoc(int stdin_copy);
int				handle_dup_error_heredoc(int fd[2]);
void			handle_child_loop_heredoc(int fd[2],
					char *delimiter, t_shell *data);
/* -------------------------------------------------------------------------- */
int				handle_append(t_ast_node *node, t_shell *data);

/* --------------------------- INPUT - Expand ENV --------------------------- */
char			*expand_env_var(char *arg, t_shell *data);

/* -------------------------------------------------------------------------- */
/*                                    LEXER                                   */
/* -------------------------------------------------------------------------- */
t_token			*lexer(const char *input);

/* ----------------------------- LEXER - Handler ---------------------------- */
void			handle_special_tokens(const char *input, size_t *i,
					t_token **tokens, int *id);
void			handle_quotes(const char *input, size_t *i,
					t_token **tokens, int *id);
void			handle_words(const char *input, size_t *i,
					t_token **tokens, int *id);
void			handle_paren_tokens(const char *input, size_t *i,
					t_token **tokens, int *position);

/* ------------------------------ LEXER - Token ----------------------------- */
void			add_token(t_token **tokens, t_token *new_token);
t_token			*create_token(t_token_type type, char *value, int id);
void			skip_quoted_string(const char *input, size_t *i,
					char quote_char);
void			advance_through_string(const char *input, size_t *i,
					int *is_literal);

/* ----------------------------- LEXER - Cleanup ---------------------------- */
void			free_tokenized_input(t_token *tokens);

/* -------------------------------------------------------------------------- */
/*                                   PARSER                                   */
/* -------------------------------------------------------------------------- */
/* ------------------------------ PARSER - AST ------------------------------ */
void			free_ast_node(t_ast_node *node);
void			free_ast(t_ast_node *root);
t_ast_node		*create_ast_node(t_node_type type);
t_ast_node		*create_ast_from_queue(t_queue *queue);

/* --------------------------- PARSER - Utilities --------------------------- */
int				is_special_token(t_token *token);
int				is_and_or_token(t_token *token);
int				is_operator_token(t_token *token);
int				is_command_token(t_token *token);
int				get_operator_precedence(t_ast_node *token);
int				process_token(t_token **c, t_queue *q, t_stack *s,
					t_shell *data);
void			free_stack_and_queue(t_queue *output_queue,
					t_stack *operator_stack);
t_ast_node		*parse_command(t_token *tokens, t_shell *data);
t_ast_node		*parse_tokens(t_token *tokens, t_shell *data);
t_ast_node		*create_node_based_on_token(t_token *current, t_shell *data);

/* ---------------------------- PARSER - Checkers --------------------------- */
int				check_parentheses_valid(t_token *tokens);

/* ----------------------------- PARSER - Stack ----------------------------- */
int				stack_push(t_stack *stack, t_ast_node *value);
void			stack_free(t_stack *stack);
t_stack			*stack_init(void);
t_ast_node		*stack_pop(t_stack *stack);
t_ast_node		*stack_peek(t_stack *stack);

/* ----------------------------- PARSER - Queue ----------------------------- */
int				queue_push(t_queue *queue, t_ast_node *value);
void			queue_free(t_queue *queue);
t_queue			*queue_init(void);
t_ast_node		*queue_pop(t_queue *queue);
t_ast_node		*queue_peek(t_queue *queue);

/* -------------------------------------------------------------------------- */
/*                                    ERROR                                   */
/* -------------------------------------------------------------------------- */
void			print_error(char *command, int status, char *message);

#endif
