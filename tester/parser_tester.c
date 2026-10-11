/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:16:40 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:44:19 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    char    **s;
    t_stack stack;
    t_stack tmp;
    int     i;
    int     quit;

    if (argc == 1)
    {
        printf("You didn't input any value\n");
        return (0);
    }
    s = argv;
    s++;
    stack = NULL;
    if (**s == 0)
    {
        printf("You input an empty value. Try again.");
        return (0);
    }
    printf("Have you already tested the stack operations? If not, quit.\n0 don't quit, 1 quit.\nquit = ");
    scanf("%d", &quit);
    if(quit)
        return (0);
    while (*s != NULL)
    {
        i = parser(*s, &stack);
        if (i == -1)
        {
            printf("Atoi couldn't do its job.");
            free_stack(&stack);
            return (1);
        }
        else if (i == 0)
        {
            //printf("it says it's already in the stack: an error, in this case.");
            printf("Atoi says it's already in the stack, or failed allocation, or null pointer");
            free_stack(&stack);
            return (1);
        }
        else if (i == 1)
            printf("no error returned from the parser");
        else
        {
            printf ("Error: return values from the parser unexpected");
            free_stack(&stack);
            return (1);
        }
        tmp = ft_stack_last(stack);
        printf ("The value you input is %d", tmp->content);
        printf("Is it the correct value?\n");
        s++;
    }
    printf("Test completed");
    free_stack(&stack);
    return (0);
}