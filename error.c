/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:15:15 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:43:33 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	int	error_code;

	error_code = 1;
	write(2, "Error\n", 6);
	exit(error_code);
}

void	error_string_is_empty(void)
{
	error();
}

void	error_head_is_null(void)
{
	error();
}

void	error_allocation_failed(void)
{
	error();
}
