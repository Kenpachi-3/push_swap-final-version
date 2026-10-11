/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 19:50:53 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/11 15:25:53 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int n)
{
	int	chunk_size;

	chunk_size = 0;
	while (chunk_size * chunk_size <= n)
	{
		chunk_size++;
	}
	return (chunk_size - 1);
}

void	get_chunk_bounds(int chunk_index, int k, int *lowest, int *highest)
{
	*lowest = chunk_index * k;
	*highest = *lowest + k - 1;
}

int	move_to_top_and_push_b(t_stack *a, t_stack *b, int lowest, int highest)
{
	int	pos;

	pos = find_nearest_in_chunk(*a, lowest, highest);
	if (pos == -1)
		return (0);
	stack_value_to_the_top(a, content_at(*a, pos), pos);
	pb(a, b);
	return (1);
}

void	b_to_top(t_stack *b, int pos)
{
	int	len;
	int	i;

	len = ft_stack_len(*b);
	i = 0;
	if (pos <= len / 2)
	{
		while (i++ < pos)
			rb(b);
	}
	else
	{
		while (i++ < len - pos)
			rrb(b);
	}
}

void	chunk_sort(t_stack *a, t_stack *b, int n)
{
	int	k;
	int	num_chunks;
	int	chunk_index;
	int	lowest;
	int	highest;

	k = get_chunk_size(n);
	assign_index(a);
	num_chunks = n / k;
	chunk_index = 0;
	while (chunk_index < num_chunks)
	{
		get_chunk_bounds(chunk_index, k, &lowest, &highest);
		if (chunk_index == num_chunks - 1)
			highest = n - 1;
		while (move_to_top_and_push_b(a, b, lowest, highest))
			;
		chunk_index++;
	}
	while (*b)
	{
		b_to_top(b, find_max_pos(*b));
		pa(a, b);
	}
}
