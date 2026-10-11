/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_tokenizer_tester.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:16:26 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:44:13 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    char    **s;
    t_stack stack;
    int     quit;

    printf("Have you already tested parser and the stack operations? If not, quit.\n0 don't quit, 1 quit.\nquit = ");
    scanf("%d", &quit);
    if(quit)
        return (0);
    if (argc == 1)
    {
        printf("You didn't input any value\n");
        return (0);
    }
    s = argv;
    s++;
    stack = NULL;
    printf("this is tokenising and parsing only the first element of the argv, if you input more values they won't be considered.\n");
    tokenizer(*s, &stack);
    ft_print_stack(stack, "horiz");
    free_stack(&stack);
    return (0);
}