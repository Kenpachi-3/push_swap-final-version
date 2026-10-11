/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:17:45 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:42:27 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  (src == NULL || dest == NULL)   :   ERROR TO BE MANAGED
static int	push(t_stack *dest, t_stack *src)
{
	t_stack	tmp;

	if (src == NULL || dest == NULL)
		return (1);
	if (*src == NULL)
		return (1);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	return (0);
}

void	pa(t_stack *head_a, t_stack *head_b)
{
	int	check;

	check = push(head_a, head_b);
	if (check)
		return ;
	ft_printf("pa\n");
}

void	pb(t_stack *head_a, t_stack *head_b)
{
	int	check;

	check = push(head_b, head_a);
	if (check)
		return ;
	ft_printf("pb\n");
}
