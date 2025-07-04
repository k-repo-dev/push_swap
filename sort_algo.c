/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:04:18 by krepo             #+#    #+#             */
/*   Updated: 2025/07/04 10:44:24 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_b(t_stack_node **a, t_stack_node **b);
static void	move_b_to_a(t_stack_node **a, t_stack_node **b);
static void	min_on_top(t_stack_node **a);

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	pb(b, a, false);
	pb(b, a, false);
	while (stack_len(*a) > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (!cheapest_node)
		return ;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	if (*b && (*b)->target_node)
	{
		prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b, false);
	}
}

static void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min_node;

	min_node = find_min(*a);
	if (!min_node)
		return ;
	while ((*a)->value != min_node->value)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
