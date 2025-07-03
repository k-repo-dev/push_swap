/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_finders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:30:05 by krepo             #+#    #+#             */
/*   Updated: 2025/07/03 13:13:48 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min_val;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_val = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max_val;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_val = LONG_MIN;
	max_node = NULL;
	while (stack)
	{
		if (stack->value > max_val)
		{
			max_val = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
