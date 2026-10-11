/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:07:35 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:42:15 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//simple by pushing in b
//printf make sure the operations are written in stdout
void	min_max(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	min;

	if (stack_a == NULL || stack_b == NULL)
		error();
	if (*stack_a == NULL || *stack_b != NULL)
		error();
	while ((*stack_a)->next != NULL)
	{
		index = ft_find_min(*stack_a, &min);
		stack_value_to_the_top(stack_a, min, index);
		pb(stack_a, stack_b);
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
