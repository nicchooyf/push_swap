/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:04:33 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/24 23:34:45 by nchoo            ###   ########.fr       */
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

void	free_list(t_struct **list);

int	get_size(t_struct *stack);
t_struct	*assign_index(t_struct *stack, int index);
t_struct	*split_arg(char *s);

void	swap(t_struct **stack, int c);
void	rotate(t_struct **stack, int c);
void	reverse_rotate(t_struct **stack, int c);

void	push(t_struct **src, t_struct **des, int c);
void	smart_push(t_struct **stack_a, t_struct **stack_b, int	size);
void	push_cheapest(t_struct **stack_a, t_struct **stack_b, int pos);

int	is_sorted(t_struct *stack);
int	check_index(t_struct *stack, int half);

int	check_arg(char *arg);

void	sort_three(t_struct **stack);

int	find_cheapest(t_struct	**stack_b);
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