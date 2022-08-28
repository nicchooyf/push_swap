/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:04:33 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/28 09:28:59 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct s_struct
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_struct	*next;
}	t_struct;

/* ************************************************************************** */
/*                                MANDATORY                                   */
/* ************************************************************************** */

/* --- linked_list.c --- */
t_struct	*new_node(int value);
t_struct	*list_last(t_struct *node);
t_struct	*remove_front(t_struct **head);
void		add_back(t_struct **head, t_struct *node);
void		add_front(t_struct **head, t_struct *node);

/* --- free.c --- */
void		free_list(t_struct *head);

/* --- stack_utils.c --- */
int			get_size(t_struct *stack);
t_struct	*fill_stack(int ac, char **av);
t_struct	*assign_index(t_struct *stack, int index);
t_struct	*split_arg(char *s);

/* --- operators.c --- */
void		swap(t_struct **stack, int c);
void		rotate(t_struct **stack, int c);
void		reverse_rotate(t_struct **stack, int c);
void		do_rr(t_struct **stack_a, t_struct **stack_b, int n);
void		do_rrr(t_struct **stack_a, t_struct **stack_b, int n);

/* --- push.c --- */
void		push(t_struct **src, t_struct **des, int c);
void		smart_push(t_struct **stack_a, t_struct **stack_b, int size);
void		check_both(t_struct *tmp, t_struct **stack_a, t_struct **stack_b);
void		cheapest_to_top(t_struct **stack_a, int cost, int c);
void		push_cheapest(t_struct **stack_a, t_struct **stack_b, int pos);

/* --- sort_check.c --- */
int			is_sorted(t_struct *stack);
int			check_index(t_struct *stack, int half);

/* --- error.c --- */
int			check_arg(char *arg);
int			check_num(char *arg);

/* --- sort_three.c --- */
void		sort_three(t_struct **stack);

/* --- do_sort.c --- */
void		final_rotate(t_struct **stack_a, int half);
int			find_cheapest(t_struct	**stack_b);
void		sort_big(t_struct **stack_a, t_struct **stack_b, int size);
void		do_sort(t_struct **stack_a, t_struct **stack_b, int size);

/* --- position.c --- */
void		set_position(t_struct **stack);
void		set_target_pos(t_struct **stack_a, t_struct **stack_b);
void		calc_target(t_struct *node, t_struct **stack_a);
void		calc_target2(t_struct *node, t_struct **stack_a);

/* --- cost.c --- */
int			absolute_cost(t_struct *node);
void		calculate_cost_a(t_struct **stack_a, t_struct *node, int size);
void		calculate_cost_b(t_struct *stack_b, int size);
void		calculate_cost(t_struct **stack_a, t_struct **stack_b);

/* ************************************************************************** */
/*                                BONUS                                  	  */
/* ************************************************************************** */

/* --- bonus_do_check.c --- */
int			check_operations(int i, int size, t_struct *stack);
void		do_operation(t_struct **stack_a, t_struct **stack_b, char *s);
void		do_check(t_struct **stack_a, t_struct **stack_b);

/* --- bonus_error.c --- */
void		exit_ok(void);
void		exit_ko(void);
void		exit_error(void);

#endif