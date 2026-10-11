/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 18:20:15 by ntshuma           #+#    #+#             */
/*   Updated: 2026/08/02 19:18:48 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int					count;
	unsigned long int	addr;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	write(1, "0x", 2);
	addr = (unsigned long int)ptr;
	count += ft_putptr_hex(addr);
	return (count);
}

int	ft_putptr_hex(unsigned long int addr)
{
	int		count;
	int		remainder;
	char	c;

	count = 0;
	if (addr >= 16)
	{
		count += ft_putptr_hex(addr / 16);
	}
	remainder = addr % 16;
	if (remainder < 10)
	{
		c = remainder + '0';
		write(1, &c, 1);
		count++;
	}
	else
	{
		c = remainder - 10 + 'a';
		write(1, &c, 1);
		count++;
	}
	return (count);
}
