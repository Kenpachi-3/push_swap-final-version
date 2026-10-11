/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:45:19 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 19:43:06 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_char(int c);
int	ft_print_int(int n);
int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr);
int	ft_print_deci(long int num, char format);
int	ft_print_hexa(unsigned int hexa, char format);
int	ft_print_percent(void);
int	ft_putptr_hex(unsigned long int addr);
int	ft_handle_specifier(char spec, va_list args);
int	ft_printf(const char *str, ...);

#endif
