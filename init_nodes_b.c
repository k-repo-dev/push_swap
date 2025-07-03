/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:58:27 by krepo             #+#    #+#             */
/*   Updated: 2025/07/03 13:12:56 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b);

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		target_node = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (target_node == NULL)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
