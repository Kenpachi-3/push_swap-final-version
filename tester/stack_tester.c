/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:16:49 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/08 17:44:27 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//needs valgrind to check whether individual nodes have been freeed
//needs a flow to free nodes and stacks regardless of free_stack
int main()
{
    t_stack stack;
    t_stack tmp;
    int     choice;
    int     i;
    int     n;

    stack = NULL;
    tmp = stack;
    choice = 1;

    printf("Type a number for a new node to initialize the stack.\nnumber = ");
    scanf("%d", &n);
    stack = ft_stack_new(n);
    if (stack == NULL)
    {
        printf("Allocation failed\n");
        return (1);
    }
    printf("Creation successful!\n\n");

    //test for 1 node or last and penultimate
    tmp = ft_stack_penultimate(stack);
    if (tmp == NULL)
        printf("ft_stack_penultimate returned NULL: tested for 1 values: CORRECT\n\n)");
    else
        printf("penultimate is not NULL as it should for one node : ERROR\n\n");
    tmp = ft_stack_last(stack);
    if (tmp == NULL)
        printf("ft_stack_last returned NULL, error: tested for 1 value\n\n");
    else
        printf("last is %d: it works for 1 value\n\n", tmp->content);

    printf("Type one-digit number for a new node to add at the end.\nnumber = ");
    scanf("%d", &n);
    ft_stack_add_end(&stack, ft_stack_new(n));
    if (stack->next == NULL)
    {
        printf("ft_stack_add_end doesn't work\n\n");
        return (1);
    }
    if (stack->next->content != n)
    {
        printf("ft_stack_add_end doesn't work\n\n");
        return (1);
    }
    
    printf("ft_stack_add_end worked!\n\n");

    //test last and penultimate for 2 nodes
    tmp = ft_stack_penultimate(stack);
    if (tmp == NULL)
        printf("ft_stack_penultimate returned NULL: tested for 2 values: ERROR\n\n)");
    else
        printf("penultimate is %d, tested for 2 values: if they agree, it works\n\n", tmp->content);
    tmp = ft_stack_last(stack);
    if (tmp == NULL)
        printf("ft_stack_last returned NULL, error: tested for 1 value\n\n");
    else
        printf("last is %d: it works for 1 value\n\n", tmp->content);
    tmp = stack->next;
    i = 2;
    while (choice == 1)
    {
        printf("Type one-digit number for a new node to add at the end.\nnumber = ");
        scanf("%d", &n);
        ft_stack_add_end(&stack, ft_stack_new(n));
        i++;
        printf("%dth node created. Add new node?\n0 no\n1 yes\nchoice", i);
        scanf("%d", &choice);
    }
    n = ft_stack_len(stack);
    if (n == i)
        printf("ft_stack_len works and len is %d\n\n", n);
    else
    {
        printf("ft_stack_len doesn't work\n\n");
        return (1);
    }
    tmp = ft_stack_penultimate(stack);
    if (tmp == NULL)
        printf("ft_stack_penultimate returned NULL: tested for more than 2 values\n\n)");
    else
        printf("penultimate is %d: it works for more than 2 values\n\n", tmp->content);
    tmp = ft_stack_last(stack);
    if (tmp == NULL)
        printf("ft_stack_last returned NULL, error: tested of more than 2 values\n\n");
    else
        printf("last is %d: it works for more than 2 values\n\n", tmp->content);
    i = (ft_find_max(stack, &n));
    printf("max is %d and position is %d\n", n, i);
    printf("Check manually whether they're correct\n\n");
    i = (ft_find_min(stack, &n));
    printf("min is %d and position is %d\n", n, i);
    printf("Check manually whether they're correct\n\n");
    stack_value_to_the_top(&stack, n, i);
    if (stack->content == n)
        printf("stack_value_to_the_top works: min correctly at the top!\nCheck manually\n\n");
    else
    {
        printf("stack_value_to_the_top doesn't work\ncheck manually\n\n");
    }
    ft_print_stack(stack, "horiz");
    printf("\nDid the print horizontally work?\n");
    ft_print_stack(stack, "vert");
    printf("\nDid the print vertically work?\n");
    free_stack(&stack);
    if (stack == NULL)
        printf("free_stack works: operations checked");
    else
    {
        printf("free_stack doesn't work: memory leak");
        return (1);
    }
    printf("test completed\n");
    return (0);
}

/*

La modifica principale è corretta: ora stack resta la testa della lista.
Hai tolto la precedente assegnazione che la spostava su stack->next;
perciò lunghezza, ricerche, stampa e liberazione operano sullo stack completo.
Anche i test di ft_stack_penultimate e ft_stack_last per uno e due 
nodi hanno senso.

Restano questi punti nel codice attivo:

Non puoi fermarti a uno o due nodi. Dopo il primo nodo aggiungi 
obbligatoriamente il secondo; poi il ciclo parte con choice = 1 
e aggiunge obbligatoriamente il terzo prima di chiedere se continuare. 
Quindi il minimo testabile è tre nodi.
La variabile tmp viene impostata a stack->next dopo i controlli sui 
due nodi, ma da lì in poi non viene più usata. Non rompe il flusso, 
però è un’assegnazione superflua e può confondere sul fatto che stack 
resti la testa.
Se fallisce l’allocazione del secondo nodo, il controllo su stack->next
rileva il fallimento. Nel ciclo successivo, invece, un’allocazione 
fallita non viene controllata subito: ft_stack_add_end ignora il nodo 
nullo e il conteggio i avanza comunque; te ne accorgi solo confrontando 
la lunghezza finale.
Il messaggio per ft_stack_last nel test dei due nodi dice ancora 
“tested for 1 value”: è solo testo diagnostico, non influenza la funzione.
Il controllo finale di free_stack conferma che la testa diventa NULL,
ma non prova da solo che la memoria sia stata
effettivamente liberata;
hai già detto che per ora stai trattando la verifica con Valgrind separatamente.
Per il resto, la sequenza minimo/posizione → stack_value_to_the_top → 
confronto del contenuto in testa è coerente. Non vedo in questa versione 
gli errori strutturali precedenti. Non ho potuto compilare il tester qui,
quindi non posso confermare il risultato della build.

*/