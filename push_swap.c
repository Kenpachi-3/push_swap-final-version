/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:15:23 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/11 19:28:39 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**s;
	int		strategy;

	if (argc == 1)
		return (0);
	strategy = 0;
	stack_a = NULL;
	stack_b = NULL;
	s = argv;
	s++;
	flag_checker(&s, &strategy);
	if (*s == NULL)
		return (0);
	while (*s != NULL)
	{
		tokenizer(*s, &stack_a);
		s++;
	}
	algorithm_selector(strategy, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
