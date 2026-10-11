/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_deci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 19:16:16 by ntshuma           #+#    #+#             */
/*   Updated: 2026/08/01 20:59:49 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_deci(long int num, char format)
{
	int		count;
	int		remainder;
	char	c;

	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}
	if (num >= 10)
	{
		count += ft_print_deci(num / 10, format);
	}
	remainder = num % 10;
	c = remainder + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
