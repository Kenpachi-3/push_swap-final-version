/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:16:07 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:43:58 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main()
{
    t_stack stack_a;
    t_stack stack_b;
    t_stack tmp;
    t_stack tmp_node;
    int     choice;
    float   disorder;
    int     i;
    int     n;
    
    printf("Have you already tested the stack operations? If not, quit.\n0 don't quit, 1 quit.\nquit = ");
    scanf("%d", &choice);
    if(choice)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    choice = 1;
    /*
    printf("Enter the fist value (the ->content of the first node, an int)\nContent = ");
    scanf("%d", &choice);
    tmp = ft_stack_new(choice);
    if (tmp == NULL)
    {
        printf("Allocation failed\n");
        free_stack(stack_a);
        free_stack(stack_b);
        return (1);
    }
    i = 1;
    while (choice == 1)
    {
        printf("Enter the fist value (the ->content of the first node, an int)\nContent = ");
        scanf("%d", &choice);
        tmp = ft_stack_new(choice);
        if (tmp == NULL)
        {
            printf("Allocation failed\n");
            free_stack(stack_a);
            free_stack(stack_b);
            return (1);
        }
        tmp = tmp->next;
        i++;
        printf("%dth node created. Add new node?\n0 no\n1 yes\nchoice", i);
        scanf("%d", &choice);
    }*/

    //stack creation
    printf("Type a number for a new node to initialize the stack.\nnumber = ");
    scanf("%d", &n);
    stack_a = ft_stack_new(n);
    if (stack_a == NULL)
    {
        printf("Allocation failed\n");
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (1);
    }
    i = 1;
    tmp = stack_a;
    printf("Add new nodes?\n0 no\t1 yes\nchoice = ");
    scanf("%d", &choice);
    while (choice == 1)
    {
        printf("Type one-digit number for a new node to add at the end.\nnumber = ");
        scanf("%d", &n);
        tmp_node = ft_stack_new(n);
        if (tmp_node == NULL)
        {
            printf("Error allocating new nodes");
            free_stack(&stack_a);
            free_stack(&stack_b);
            return (1);
        }
        ft_stack_add_end(&stack_a, tmp_node);
        if (tmp->next == NULL)
        {
            printf("Error adding new nodes");
            free_stack(&stack_a);
            free_stack(&stack_b);
            return (1);
        }
        i++;
        tmp = tmp->next;
        printf("%dth node created.\n", i);
        printf("Add new node?\n0 no\t1 yes\nchoice = ");
        scanf("%d", &choice);
    }
    disorder = ft_disorder_metric(stack_a);
    if (disorder < 0 || disorder > 1)
    {
        printf("ft_disorder_metric returns an incorrect value (dis < 0 or dis > 1)");
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (1);
    }
    printf("what algorithm do you want to test?\n0 Simple\t1 Medium\t2 Complex\t3 Adaptive\nchoice = ");
    scanf("%d", &choice);
    if (choice == 0)
        min_max(&stack_a, &stack_b);
    else if (choice == 1)
        {}//chunk_sort(&stack_a, &stack_b, ft_stack_len(stack_a));
    else if (choice == 2)
        radix(&stack_a, &stack_b);
    else if (choice == 3)
        adaptive (disorder, &stack_a, &stack_b);
    else
    {
        printf("bad choice for algorithm, Quit");
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (1);
    }
    printf("\nstack_a:\n");
    ft_print_stack(stack_a, "horiz");
    printf("\nstack_b:\n");
    ft_print_stack(stack_b, "horiz");
    printf ("Is stack_a ordered? Is stack_b empty?");
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}