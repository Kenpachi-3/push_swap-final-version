/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 15:09:42 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/11 19:07:25 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_nearest_in_chunk(t_stack stack, int lowest, int highest)
{
	int		first;
	int		last;
	int		pos;
	t_stack	tmp;

	first = -1;
	last = -1;
	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (lowest <= tmp->index && tmp->index <= highest)
		{
			if (first == -1)
				first = pos;
			last = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (first == -1)
		return (-1);
	if (first > ft_stack_len(stack) - last)
		return (last);
	return (first);
}

int	content_at(t_stack stack, int pos)
{
	while (pos > 0)
	{
		stack = stack->next;
		pos--;
	}
	return (stack->content);
}

int	find_max_pos(t_stack b)
{
	int	pos;
	int	max_pos;
	int	max_index;

	pos = 0;
	max_pos = 0;
	max_index = b->index;
	while (b)
	{
		if (b->index > max_index)
		{
			max_index = b->index;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}
