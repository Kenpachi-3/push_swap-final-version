/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:17:33 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:42:47 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*unnecessary_zero_remover(char *s)
{
	char	*next_char;

	if (!s)
		error_string_is_empty();
	next_char = s;
	if (*next_char)
		next_char++;
	while (*s == '0' && *next_char != 0)
	{
		s++;
		next_char++;
	}
	return (s);
}

static int	check_overflow(int *num, int *digit, int *len)
{
	if (*len == 10)
		return (2);
	else if (*len == 9)
	{
		if (*num > 214748364 || *num < -214748364)
			return (1);
		else if ((*num == 214748364 && *digit > 7)
			|| (*num == -214748364 && *digit > 8))
			return (1);
	}
	return (0);
}

static void	check_sign(char **s, int *sign)
{
	*sign = 1;
	if (**s == '+')
		(*s)++;
	else if (**s == '-')
	{
		*sign = -1;
		(*s)++;
	}
}

static int	modified_atoi(char **s, int *len, int *num)
{
	int	sign;
	int	digit;

	check_sign(s, &sign);
	*s = unnecessary_zero_remover(*s);
	if (**s == 0 || **s == ' ' || **s == '\t')
		return (1);
	while (**s != 0)
	{
		if (!ft_isdigit(**s))
			return (1);
		digit = **s - '0';
		if (check_overflow(num, &digit, len))
			return (1);
		*num = *num * 10 + sign * digit;
		(*len)++;
		(*s)++;
	}
	return (0);
}

//quando trovi un carattere invalido, lo attraversi
//fino allo spazio, ma non registri che il token 
//deve essere scartato;
//quando trovi overflow, vale lo stesso: raggiungi 
//il separatore, ma poi il codice continua;
//se dopo aver rimosso gli zeri rimane subito uno 
//spazio o '\0', hai un token senza cifre, 
//che dovrà essere riconosciuto come invalido.
//-1 for errors, 0 for
//      in case of error, the caller function 
//is in charge of freeing memory
//for s == NULL it's returning 0, but maybe 
//should be           error_string_is_empty()
int	parser(char *s, t_stack *head)
{
	int		len;
	int		num;
	t_stack	new_node;

	if (s == NULL)
		return (0);
	if (*s == 0)
		return (0);
	if (head == NULL)
		return (0);
	while (*s != 0)
	{
		len = 0;
		num = 0;
		if (modified_atoi(&s, &len, &num))
			return (-1);
		if (!is_not_in_stack(head, num))
			return (0);
		new_node = ft_stack_new(num);
		if (new_node == NULL)
			return (0);
		ft_stack_add_end(head, new_node);
	}
	return (1);
}
