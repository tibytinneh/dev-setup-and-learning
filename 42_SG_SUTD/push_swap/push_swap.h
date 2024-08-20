/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:32:50 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 16:40:01 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	int				rank;
	struct s_stack	*next;
	struct s_stack	*prev;

}				t_stack;

t_stack	*init_stack_1(char *args);
t_stack	*init_stack_2(int ac, char **av);
t_stack	*init_pushswap(int ac, char **av);
int		input_check(char *arg);
int		duplicate_check(t_stack *a);
void	error_handler(void);
void	error_handler_free_stack(t_stack **stack);
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_free(char **str);
char	**ft_split(char const *s, char c);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *s1);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	swap_two_nodes(t_stack **head);
void	swap_more_than_two_nodes(t_stack **head);
void	swap(t_stack **head);
int		init_stack_rank(t_stack **stack);
void	free_stack(t_stack **a);
void	ft_print_stack(t_stack *lst);
int		get_stack_len(t_stack *stack);
void	rank_nodes(t_stack *stack);
void	lst_push_front(t_stack **lst, int new_nbr);
void	lst_push_back(t_stack **lst, int new_nbr);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	detach_node(t_stack **head, t_stack *node);
void	attach_node(t_stack **head, t_stack *node);
void	push_node(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	rotate(t_stack	**head);
void	reverse_rotate(t_stack	**head);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort_size_2(t_stack **a);
void	sort_size_3(t_stack **a);
void	sort_size_4(t_stack **a, t_stack **b);
void	sort_size_5(t_stack **a, t_stack **b);
int		number_of_bits(int count);
int		is_sorted(t_stack *stack);
void	nuke_b_back(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b, int bits_num);

#endif
