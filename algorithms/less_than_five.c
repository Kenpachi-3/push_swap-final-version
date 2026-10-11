/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:08:21 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/11 17:38:41 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two(t_stack *stack)
{
	if ((*stack)->content > (*stack)->next->content)
	{
		sa(stack);
	}
}

static void	three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && a > c)
	{
		ra(stack);
	}
	else if (a > b)
		sa(stack);
	else if (b > c && a > c)
		rra(stack);
	else if (b > c)
	{
		sa(stack);
		ra(stack);
	}
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	t_stack	tmp;
	int		pos;
	int		min_pos;
	int		min;

	tmp = *a;
	pos = 0;
	min_pos = 0;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	stack_value_to_the_top(a, min, min_pos);
	pb(a, b);
}

static void	sort_small(t_stack *a, t_stack *b, int len)
{
	while (len > 3)
	{
		push_min_to_b(a, b);
		len--;
	}
	three(a);
	while (*b)
		pa(a, b);
}

void	less_than_five(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (stack_a == NULL || stack_b == NULL || *stack_b != 0)
		error();
	if (len == 0 || len == 1)
		return ;
	if (len == 2)
		two(stack_a);
	else if (len == 3)
		three(stack_a);
	else if (len == 4 | len == 5)
		sort_small(stack_a, stack_b, len);
	else
		error();
}
