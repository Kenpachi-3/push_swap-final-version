/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:17:52 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:42:32 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack *head)
{
	t_stack	tmp_first;
	t_stack	tmp_last;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);
	tmp_first = *head;
	tmp_last = ft_stack_last(*head);
	ft_stack_penultimate(*head)->next = NULL;
	tmp_last->next = tmp_first;
	*head = tmp_last;
	return (0);
}

void	rra(t_stack *head_a)
{
	int	check;

	check = reverse_rotate(head_a);
	if (check)
		return ;
	ft_printf("rra\n");
}

void	rrb(t_stack *head_b)
{
	int	check;

	check = reverse_rotate(head_b);
	if (check)
		return ;
	ft_printf("rrb\n");
}

void	rrr(t_stack *head_a, t_stack *head_b)
{
	int	check;

	check = reverse_rotate(head_a);
	check *= reverse_rotate(head_b);
	if (check)
		return ;
	ft_printf("rrr\n");
}
