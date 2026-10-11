/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:15:55 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:43:22 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//tmp_fixed         points to a node, against 
//which the following nodes are compared
//tmp_changing      points to a node after the "fixed" one
///if no stack then no disorder (return 0)
//while the main node is not the last
//initialize the contrasting node as the main node
//while there are still nodes to compare after this one
//RETURN converts mistakes to float which is enough to get a float as a result
float	ft_disorder_metric(t_stack a)
{
	long long int	mistakes;
	long long int	total_pairs;
	t_stack			tmp_fixed;
	t_stack			tmp_changing;

	if (a == NULL)
		return (0);
	else if (a->next == NULL)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	tmp_fixed = a;
	while (tmp_fixed->next)
	{
		tmp_changing = tmp_fixed;
		while (tmp_changing->next)
		{
			total_pairs += 1;
			tmp_changing = tmp_changing->next;
			if (tmp_fixed->content > tmp_changing->content)
				mistakes += 1;
		}
		tmp_fixed = tmp_fixed->next;
	}
	return ((float)mistakes / total_pairs);
}
