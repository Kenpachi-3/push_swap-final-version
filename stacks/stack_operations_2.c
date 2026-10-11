/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:17:14 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/11 18:54:26 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack stack, char *s)
{
	if (stack == NULL)
	{
		ft_printf("No stack found.\n");
		return ;
	}
	if (ft_strncmp(s, "horiz", 6) == 0)
		s = " ";
	else if (ft_strncmp(s, "vert", 5) == 0)
		s = "\n";
	while (stack)
	{
		ft_printf("%d%s", stack->content, s);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	ft_find_min(t_stack stack, int *min)
{
	int		pos;
	int		tmp_pos;
	int		tmp_min;
	t_stack	tmp_stack;

	if (stack == NULL)
		error_head_is_null();
	pos = 0;
	tmp_pos = 1;
	tmp_min = stack->content;
	tmp_stack = stack->next;
	while (tmp_stack != NULL)
	{
		if (tmp_stack->content < tmp_min)
		{
			pos = tmp_pos;
			tmp_min = tmp_stack->content;
		}
		tmp_stack = tmp_stack->next;
		tmp_pos++;
	}
	*min = tmp_min;
	return (pos + 1);
}

int	ft_find_max(t_stack stack, int *max)
{
	int		pos;
	int		tmp_pos;
	int		tmp_max;
	t_stack	tmp_stack;

	if (stack == NULL)
		error_head_is_null();
	pos = 0;
	tmp_pos = 1;
	tmp_max = stack->content;
	tmp_stack = stack->next;
	while (tmp_stack != NULL)
	{
		if (tmp_stack->content > tmp_max)
		{
			pos = tmp_pos;
			tmp_max = tmp_stack->content;
		}
		tmp_stack = tmp_stack->next;
		tmp_pos++;
	}
	*max = tmp_max;
	return (pos + 1);
}

int	ft_find_max_index(t_stack stack, int *max)
{
	int		pos;
	int		tmp_pos;
	int		tmp_max;
	t_stack	tmp_stack;

	if (stack == NULL)
		error_head_is_null();
	pos = 0;
	tmp_pos = 1;
	tmp_max = stack->index;
	tmp_stack = stack->next;
	while (tmp_stack != NULL)
	{
		if (tmp_stack->index > tmp_max)
		{
			pos = tmp_pos;
			tmp_max = tmp_stack->index;
		}
		tmp_stack = tmp_stack->next;
		tmp_pos++;
	}
	*max = tmp_max;
	return (pos + 1);
}

int	stack_value_to_the_top(t_stack *stack, int min, int index)
{
	int	rotations;

	if (stack == NULL)
		error();
	if (*stack == NULL)
		error();
	rotations = 0;
	if (index <= ft_stack_len(*stack) / 2 + 1)
	{
		while ((*stack)->content != min)
		{
			ra(stack);
			rotations++;
		}
	}
	else
	{
		while ((*stack)->content != min)
		{
			rra(stack);
			rotations++;
		}
	}
	return (rotations);
}
