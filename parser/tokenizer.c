/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:17:39 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 19:36:55 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	tab_remover(char **tab)
{
	*tab = ft_strchr(*tab, '\t');
	if (*tab == NULL)
		return (1);
	**tab = ' ';
	(*tab)++;
	return (0);
}

//s = NULL to signal the change of owner, safety measure
//*tokens == NULL   :   malloc failing allocation failed
//**tokens == NULL  :   no numbers: invalid input error:
// error(), but now is treated as a memory allocation issue
//      SEPARATE THE TWO ERROR CONDITIONS!!!!
static int	token_extraction(char **s, char ***tokens)
{
	*tokens = ft_split(*s, ' ');
	free(*s);
	if (*tokens == NULL)
	{
		free(*tokens);
		return (1);
	}
	if (**tokens == NULL)
	{
		free(*tokens);
		return (1);
	}
	return (0);
}

static int	token_insertion_in_stack(char ***tokens, t_stack *head)
{
	char	**tmp;
	int		parser_return_value;

	tmp = *tokens;
	while (*tmp)
	{
		parser_return_value = parser(*tmp, head);
		if (parser_return_value == -1 || parser_return_value == 0)
		{
			while (*tmp)
			{
				free(*tmp);
				tmp++;
			}
			free(*tokens);
			return (1);
		}
		free(*tmp);
		tmp++;
	}
	free(*tokens);
	return (0);
}

static void	tokenizer_interruptor(int n, t_stack *head)
{
	free_stack(head);
	if (n == 0)
		error_allocation_failed();
	else if (n == 1)
		error();
}

void	tokenizer(char *argv_arg, t_stack *head)
{
	char	*s;
	char	*tab;
	char	**tokens;

	if (argv_arg == NULL)
		tokenizer_interruptor(1, head);
	s = NULL;
	s = ft_strdup(argv_arg);
	if (s == NULL)
		tokenizer_interruptor(0, head);
	tab = s;
	while (*tab)
		if (tab_remover(&tab))
			break ;
	if (token_extraction(&s, &tokens))
		tokenizer_interruptor(0, head);
	if (token_insertion_in_stack(&tokens, head))
		tokenizer_interruptor(1, head);
}
