/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:18:05 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:42:40 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//if no ptr to the head
//if there are not at least two nodes in the stack, do nothing
static int	swap(t_stack *head)
{
	t_stack	second_node_ptr;
	t_stack	third_node_ptr;

	if (head == NULL)
		return (1);
	if (*head == NULL || (*head)->next == NULL)
		return (1);
	second_node_ptr = (*head)->next;
	third_node_ptr = second_node_ptr->next;
	(*head)->next->next = *head;
	(*head)->next = third_node_ptr;
	*head = second_node_ptr;
	return (0);
}

void	sa(t_stack *head_a)
{
	int	check;

	check = swap(head_a);
	if (check)
		return ;
	ft_printf("sa\n");
}

void	sb(t_stack *head_b)
{
	int	check;

	check = swap(head_b);
	if (check)
		return ;
	ft_printf("sb\n");
}

void	ss(t_stack *head_a, t_stack *head_b)
{
	int	check;

	check = swap(head_a);
	check *= swap(head_b);
	if (check)
		return ;
	ft_printf("ss\n");
}
