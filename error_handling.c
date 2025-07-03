/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:50:52 by krepo             #+#    #+#             */
/*   Updated: 2025/07/03 13:21:00 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_nbr)
{
	int	i;

	i = 0;
	if (str_nbr[i] == '\0')
		return (1);
	if (str_nbr[i] == '+' || str_nbr[i] == '-')
		i++;
	if (!(str_nbr[i] >= '0' && str_nbr[i] <= '9'))
		return (1);
	while (str_nbr[i])
	{
		if (!(str_nbr[i] >= '0' && str_nbr[i] <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_matrix(char *av[])
{
	int	i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
