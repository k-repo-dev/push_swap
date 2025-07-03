/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:49:16 by krepo             #+#    #+#             */
/*   Updated: 2025/07/03 13:34:11 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char			**ft_split(char *str, char delimiter);
void			free_matrix(char *av[]);
void			free_errors(t_stack_node **a);
void			free_stack(t_stack_node **stack);
int				error_repetition(t_stack_node *a, int nbr);
int				error_syntax(char *str_nbr);
void			stack_init_a(t_stack_node **a, char *av[]);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			append_node(t_stack_node **stack, int nbr);
long			ft_atol(const char *str);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);

#endif
