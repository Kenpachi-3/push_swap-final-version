/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:15:44 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/11 19:33:31 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	flag_simple_medium(char ***s, int *strategy)
{
	if (ft_strncmp(**s, "--simple", 9) == 0)
	{
		*strategy = 1;
		(*s)++;
		return (1);
	}
	else if (ft_strncmp(**s, "--medium", 9) == 0)
	{
		*strategy = 2;
		(*s)++;
		return (1);
	}
	return (0);
}

static int	flag_complex_adaptive(char ***s, int *strategy)
{
	if (ft_strncmp(**s, "--complex", 10) == 0)
	{
		*strategy = 3;
		(*s)++;
		return (1);
	}
	else if (ft_strncmp(**s, "--adaptive", 11) == 0)
	{
		*strategy = 0;
		(*s)++;
		return (1);
	}
	return (0);
}

void	flag_checker(char ***s, int *strategy)
{
	if (flag_simple_medium(s, strategy))
		return ;
	flag_complex_adaptive(s, strategy);
		return ;
}
