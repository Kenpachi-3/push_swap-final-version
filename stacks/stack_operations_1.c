/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:17:08 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:43:04 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_stack_new(int num)
{
	t_stack	new_node_ptr;

	new_node_ptr = malloc(sizeof(t_node));
	if (new_node_ptr == NULL)
		return (NULL);
	new_node_ptr->content = num;
	new_node_ptr->index = -1;
	new_node_ptr->next = NULL;
	return (new_node_ptr);
}

int	ft_stack_len(t_stack stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 1;
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	ft_stack_penultimate(t_stack stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (NULL);
	else
	{
		while (stack->next->next)
			stack = stack->next;
	}
	return (stack);
}

t_stack	ft_stack_last(t_stack stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stack_add_end(t_stack *head, t_stack node_ptr)
{
	if (head == NULL || node_ptr == NULL)
		return ;
	if (*head == NULL)
		*head = node_ptr;
	else
		ft_stack_last(*head)->next = node_ptr;
}
