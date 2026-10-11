/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:17:24 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/09 18:43:33 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *head)
{
	t_stack	stack;

	if (head == NULL)
		return ;
	if (*head == NULL)
		return ;
	while (*head != NULL)
	{
		stack = (*head)->next;
		free(*head);
		*head = stack;
	}
}

int	is_not_in_stack(t_stack *head, int num)
{
	t_stack	ptr;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);
	ptr = *head;
	while (ptr != NULL)
	{
		if (ptr->content == num)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	assign_index(t_stack *stack)
{
	int		rank;
	t_stack	tmp1;
	t_stack	tmp2;

	if (stack == NULL)
		return (1);
	if (*stack == NULL)
		return (1);
	tmp1 = *stack;
	while (tmp1 != NULL)
	{
		tmp2 = *stack;
		rank = 0;
		while (tmp2 != NULL)
		{
			if (tmp2->content < tmp1->content)
				rank++;
			tmp2 = tmp2->next;
		}
		tmp1->index = rank;
		tmp1 = tmp1->next;
	}
	return (0);
}
