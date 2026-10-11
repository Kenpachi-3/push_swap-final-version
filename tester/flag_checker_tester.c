/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker_tester.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:16:12 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:44:03 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int     strategy;
    int     pseudo_argc;
    char    **s;

    if (argc != 2)
    {
        printf("Requires a flag:\n--simple\t--medium\t--complex\t--adaptive\n");
        return (1);
    }
    s = argv;
    strategy = -1;
    /*printf("0 = adaptive\n1 = simple\n2 = medium\n3 = complex\nstrategy = ");
    scanf("%d", &strategy);
    if (strategy < 0 || strategy > 3)
    {
        printf("Error! Wrong number for strategy.\n It is supposed to be 0 <= strategy <=3");
        return (1);
    }*/
    printf("Enter a value to simulate argc that will be passed to the flag_checker\npseudo_argc = ");
    scanf("%d", &pseudo_argc);
    flag_checker(&s, &strategy, pseudo_argc);
    printf("The strategy is %d.\n(0 = adaptive\n1 = simple\n2 = medium\n3 = complex)\nIs it coherent with you're choice?");
    return (0);
}