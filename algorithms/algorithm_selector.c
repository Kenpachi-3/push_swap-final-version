/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:07:14 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/11 18:15:29 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_selector(int strategy, t_stack *stack_a, t_stack *stack_b)
{
	float	disorder;

	disorder = ft_disorder_metric(*stack_a);
	if (disorder == 0)
		return ;
	if (strategy == 0)
		adaptive(disorder, stack_a, stack_b);
	else if (strategy == 1)
		min_max(stack_a, stack_b);
	else if (strategy == 2)
		chunk_sort(stack_a, stack_b, ft_stack_len(*stack_a));
	else if (strategy == 3)
		radix(stack_a, stack_b);
}
