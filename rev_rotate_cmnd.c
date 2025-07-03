/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_cmnd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:46:28 by krepo             #+#    #+#             */
/*   Updated: 2025/07/03 13:14:30 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack);

void	rra(t_stack_node **a, bool checker)
{
	rev_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	rev_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}
