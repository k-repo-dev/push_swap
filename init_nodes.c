/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:08:15 by krepo             #+#    #+#             */
/*   Updated: 2025/07/02 10:27:14 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_stack_node *a, t_stack_node *b);
static void	cost_analysis_a(t_stack_node *a, t_stack_node *b);

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	long			cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		stack->cheapest = false;
		if (stack->push_price < cheapest_value)
		{
			cheapest_value = stack->push_price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_value;

	while (a)
	{
		best_match_value = LONG_MIN;
		target_node = NULL;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_value)
			{
				best_match_value = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (target_node == NULL)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median)
			a->push_price = a->current_position;
		else
			a->push_price = len_a -(a->current_position);
		if (a->target_node->above_median)
			a->push_price += a->target_node->current_position;
		else
			a->push_price += len_b - (a->target_node->current_position);
		a = a->next;
	}
}
