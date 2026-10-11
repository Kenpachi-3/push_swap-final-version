/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:17:59 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:42:36 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack *head)
{
	t_stack	tmp_first;
	t_stack	tmp_last;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);
	tmp_first = *head;
	tmp_last = ft_stack_last(*head);
	*head = tmp_first->next;
	tmp_first->next = NULL;
	tmp_last->next = tmp_first;
	return (0);
}

void	ra(t_stack *head_a)
{
	int	check;

	check = rotate(head_a);
	if (check)
		return ;
	ft_printf("ra\n");
}

void	rb(t_stack *head_b)
{
	int	check;

	check = rotate(head_b);
	if (check)
		return ;
	ft_printf("rb\n");
}

void	rr(t_stack *head_a, t_stack *head_b)
{
	int	check;

	check = rotate(head_a);
	check *= rotate(head_b);
	if (check)
		return ;
	ft_printf("rr\n");
}
