/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 22:44:46 by ntshuma           #+#    #+#             */
/*   Updated: 2026/08/03 17:40:31 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_specifier(char spec, va_list args)
{
	if (spec == 'd' || spec == 'i')
		return (ft_print_deci(va_arg(args, int), spec));
	else if (spec == 'u')
		return (ft_print_deci(va_arg(args, unsigned int), spec));
	else if (spec == 'x' || spec == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), spec));
	else if (spec == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (spec == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (spec == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (spec == '%')
		return (ft_print_percent());
	return (0);
}
