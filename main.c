/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:08:45 by krepo             #+#    #+#             */
/*   Updated: 2025/07/03 14:15:38 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**args_and_init_stack(int ac, char *av[], t_stack_node **a);

int	main(int ac, char *av[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_av;

	a = NULL;
	b = NULL;
	split_av = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (1);
	split_av = args_and_init_stack(ac, av, &a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	if (split_av)
		free_matrix(split_av);
	return (0);
}

static char	**args_and_init_stack(int ac, char *av[], t_stack_node **a)
{
	char	**split_av;

	split_av = NULL;
	if (ac == 2)
	{
		split_av = ft_split(av[1], ' ');
		if (!split_av)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		stack_init_a(a, split_av);
	}
	else
		stack_init_a(a, av + 1);
	return (split_av);
}
