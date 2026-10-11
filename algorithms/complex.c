/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:10:40 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/11 19:08:41 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	divide_digit_by_power_of_2(int index, int cycles)
{
	int	i;

	i = 0;
	while (i < cycles)
	{
		index /= 2;
		i++;
	}
	return (index % 2);
}

static int	node_push(t_stack *a, t_stack *b, int list_size, int max_num)
{
	int	i;
	int	k;
	int	cycles;

	if (a == NULL || b == NULL || *a == NULL || *b != NULL)
		return (1);
	i = 1;
	cycles = 0;
	while (max_num / i > 0)
	{
		k = 0;
		while (k < list_size)
		{
			if (divide_digit_by_power_of_2((*a)->index, cycles) == 0)
				pb(a, b);
			else
				ra(a);
			k++;
		}
		cycles += 1;
		while (*b != NULL)
			pa(a, b);
		i *= 2;
	}
	return (0);
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int	*max_index;
	int	nb;

	nb = 0;
	max_index = &nb;
	if (stack_a == NULL || stack_b == NULL)
	{
		return ;
	}
	if (assign_index(stack_a))
		error();
	ft_find_max_index(*stack_a, max_index);
	if (node_push(stack_a, stack_b, ft_stack_len(*stack_a), *max_index))
		error();
}
