/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:04:33 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/25 19:24:56 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

typedef struct s_struct
{
	int				value;
	int				index;
	int 			pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_struct *next;
} 	t_struct;

t_struct	*new_node(int value);
t_struct	*list_last(t_struct *node);
t_struct	*remove_front(t_struct **head);
void	add_back(t_struct **head, t_struct *node);
void	add_front(t_struct **head, t_struct *node);

void	free_list(t_struct *head);

int	get_size(t_struct *stack);
t_struct	*fill_stack(int ac, char **av);
t_struct	*assign_index(t_struct *stack, int index);
t_struct	*split_arg(char *s);

void	swap(t_struct **stack, int c);
void	rotate(t_struct **stack, int c);
void	reverse_rotate(t_struct **stack, int c);
void	do_rr(t_struct **stack_a, t_struct **stack_b);
void	do_rrr(t_struct **stack_a, t_struct **stack_b);

void	push(t_struct **src, t_struct **des, int c);
void	smart_push(t_struct **stack_a, t_struct **stack_b, int	size);
void	check_rr_or_rrr(t_struct *tmp, t_struct **stack_a, t_struct **stack_b);
void	cheapest_to_top(t_struct **stack_a, int cost, int c);
void	push_cheapest(t_struct **stack_a, t_struct **stack_b, int pos);

int	is_sorted(t_struct *stack);
int	check_index(t_struct *stack, int half);

int	check_arg(char *arg);
int	check_num(char *arg);

void	sort_three(t_struct **stack);

void	final_rotate(t_struct **stack_a, int half);
int		find_cheapest(t_struct	**stack_b);
void	sort_big(t_struct **stack_a, t_struct **stack_b, int size);
void	do_sort(t_struct **stack_a, t_struct **stack_b, int size);

void	set_position(t_struct **stack);
void	set_target_pos(t_struct **stack_a, t_struct **stack_b);
void	calc_target(t_struct *node, t_struct **stack_a);
void	calc_target2(t_struct *node, t_struct **stack_a);

int	absolute_cost(t_struct *node);
void 	calculate_cost_a(t_struct **stack_a, t_struct *node, int size);
void	calculate_cost_b(t_struct *stack_b, int size);
void	calculate_cost(t_struct **stack_a, t_struct **stack_b);

void 	print_result(t_struct *stack_a, t_struct *stack_b);
void 	print_no_free(t_struct *stack_a, t_struct *stack_b);

#endif