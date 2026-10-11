/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:04:26 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:41:50 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//chunk_num = 2     temporary value, to be defined after medium.c is ready
//some error if disorder <0 || >1
void	adaptive(float disorder, t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	if (disorder < 0 || disorder > 1 || stack_a == NULL || stack_b == NULL)
		error();
	if (disorder == 0)
		return ;
	len = ft_stack_len(*stack_a);
	if (len > 0 && len <= 5)
	{
		less_than_five(stack_a, stack_b, len);
		return ;
	}
	if (disorder >= 0 && disorder < 0.2)
		min_max(stack_a, stack_b);
	else if (disorder >= 0.2 && disorder < 0.5)
		chunk_sort(stack_a, stack_b, len);
	else if (disorder >= 0.5 && disorder <= 1)
		radix(stack_a, stack_b);
	else
		error();
}
