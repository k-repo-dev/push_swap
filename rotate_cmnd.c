/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmnd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:55:35 by krepo             #+#    #+#             */
/*   Updated: 2025/07/03 13:22:33 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack);

void	ra(t_stack_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = find_last_node(*stack);
	*stack = first_node->next;
	(*stack)->prev = NULL;
	first_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
}
