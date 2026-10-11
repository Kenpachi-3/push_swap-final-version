/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:16:20 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:45:19 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(void)
{
    int choice;
    t_stack stack_a;
    t_stack stack_b;
    t_stack tmp;
    t_stack tmp_node;
    int     i;
    int     n;

    choice = 1;
    stack_a = NULL;
    stack_b = NULL;
    printf("If it doesn't crash, check each value manually. Hopefully it doesn't\n");
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
        if (i > 5)
        {
            printf("Add new node?\n0 no\t1 yes\nchoice = ");
            scanf("%d", &choice);
        }
    }
    printf("Expected operation: sa\n");
    fflush(stdout);
    sa(&stack_a);
    printf("Check if values are swapped\n");
    fflush(stdout);
    ft_print_stack(stack_a, "horiz");
    printf("\n");
    printf("Expected operation: ra\n");
    fflush(stdout);
    ra(&stack_a);
    printf("Check if values are rotated\n");
    fflush(stdout);
    ft_print_stack(stack_a, "horiz");
    printf("\n");
    printf("Expected operation: rra\n");
    fflush(stdout);
    rra(&stack_a);
    printf("Check if values are reverse rotated\n");
    fflush(stdout);
    ft_print_stack(stack_a, "horiz");
    printf("\n");
    printf("Expected operation: pb\n");
    fflush(stdout);
    pb(&stack_a, &stack_b);
    printf("Check if values are pushed into b\n");
    fflush(stdout);
    printf("Stack_a:\n");
    ft_print_stack(stack_a, "horiz");
    printf("Stack_b:\n");
    ft_print_stack(stack_b, "horiz");
    printf("\n");
    printf("Expected operation: pb\n");
    fflush(stdout);
    pb(&stack_a, &stack_b);
    printf("Check if values are pushed into b\n");
    fflush(stdout);
    printf("Stack_a:\n");
    ft_print_stack(stack_a, "horiz");
    printf("Stack_b:\n");
    ft_print_stack(stack_b, "horiz");
    printf("\n");
    printf("Expected operation: pb\n");
    fflush(stdout);
    pb(&stack_a, &stack_b);
    printf("Check if values are pushed into b\n");
    fflush(stdout);
    printf("Stack_a:\n");
    ft_print_stack(stack_a, "horiz");
    printf("Stack_b:\n");
    ft_print_stack(stack_b, "horiz");
    printf("\n");
    printf("Expected operation: sb\n");
    fflush(stdout);
    sb(&stack_b);
    printf("Check if values are swapped\n");
    fflush(stdout);
    ft_print_stack(stack_b, "horiz");
    printf("\n");
    printf("Expected operation: rb\n");
    fflush(stdout);
    rb(&stack_b);
    printf("Check if values are rotated\n");
    fflush(stdout);
    ft_print_stack(stack_b, "horiz");
    printf("\n");
    printf("Expected operation: rrb\n");
    fflush(stdout);
    rrb(&stack_b);
    printf("Check if values are reverse rotated\n");
    fflush(stdout);
    ft_print_stack(stack_b, "horiz");
    printf("\n");
    printf("Expected operation: ss\n");
    fflush(stdout);
    ss(&stack_a, &stack_b);
    printf("Check if values in both stacks are swapped\n");
    fflush(stdout);
    printf("Stack_a:\n");
    ft_print_stack(stack_a, "horiz");
    printf("Stack_b:\n");
    ft_print_stack(stack_b, "horiz");
    printf("\n\n");
    printf("Expected operation: rr\n");
    fflush(stdout);
    rr(&stack_a, &stack_b);
    printf("Check if values in both stacks are rotated\n");
    fflush(stdout);
    printf("Stack_a:\n");
    ft_print_stack(stack_a, "horiz");
    printf("Stack_b:\n");
    ft_print_stack(stack_b, "horiz");
    printf("\n\n");
    printf("Expected operation: rrr\n");
    fflush(stdout);
    rrr(&stack_a, &stack_b);
    printf("Check if values in both stacks are reverse rotated\n");
    fflush(stdout);
    printf("Stack_a:\n");
    ft_print_stack(stack_a, "horiz");
    printf("Stack_b:\n");
    ft_print_stack(stack_b, "horiz");
    printf("\n\n");
    printf("Expected operation: pa\n");
    fflush(stdout);
    pa(&stack_a, &stack_b);
    printf("Check if values are pushed into a\n");
    fflush(stdout);
    printf("Stack_b:\n"); 
    ft_print_stack(stack_b, "horiz");
    printf("\n");
    printf("Stack_a:\n");
    ft_print_stack(stack_a, "horiz");
    printf("\n");
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}