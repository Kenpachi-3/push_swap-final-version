/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntshuma <ntshuma@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:15:33 by ntshuma           #+#    #+#             */
/*   Updated: 2026/10/11 19:23:26 by ntshuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
}	t_node;

typedef t_node	*t_stack;

int		ft_find_max_index(t_stack stack, int *max);

void	error(void);
void	error_string_is_empty(void);
void	error_head_is_null(void);
void	error_allocation_failed(void);

void	flag_checker(char ***s, int *strategy);

t_stack	ft_stack_new(int num);
int		ft_stack_len(t_stack stack);
t_stack	ft_stack_penultimate(t_stack stack);
t_stack	ft_stack_last(t_stack stack);
void	ft_stack_add_end(t_stack *head, t_stack node_ptr);

int		ft_find_min(t_stack stack, int *min);
int		ft_find_max(t_stack stack, int *max);
int		stack_value_to_the_top(t_stack *stack, int min, int index);
void	ft_print_stack(t_stack stack, char *s);

int		find_nearest_in_chunk(t_stack stack, int lowest, int highest);
int		content_at(t_stack stack, int pos);
int		find_max_pos(t_stack b);

void	free_stack(t_stack *head);
int		is_not_in_stack(t_stack *head, int num);
int		assign_index(t_stack *stack);

float	ft_disorder_metric(t_stack a);
void	algorithm_selector(int strategy, t_stack *stack_a, t_stack *stack_b);

void	tokenizer(char *argv_arg, t_stack *head);
int		parser(char *s, t_stack *head);

void	sa(t_stack *head_a);
void	sb(t_stack *head_b);
void	ss(t_stack *head_a, t_stack *head_b);
void	pa(t_stack *head_a, t_stack *head_b);
void	pb(t_stack *head_a, t_stack *head_b);
void	ra(t_stack *head_a);
void	rb(t_stack *head_b);
void	rr(t_stack *head_a, t_stack *head_b);
void	rra(t_stack *head_a);
void	rrb(t_stack *head_b);
void	rrr(t_stack *head_a, t_stack *head_b);

void	less_than_five(t_stack *stack_a, t_stack *stack_b, int len);
void	min_max(t_stack *stack_a, t_stack *stack_b);
void	chunk_sort(t_stack *a, t_stack *b, int n);
void	radix(t_stack *stack_a, t_stack *stack_b);
void	adaptive(float disorder, t_stack *stack_a, t_stack *stack_b);

#endif