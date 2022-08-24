#include "push_swap.h"

void print_result(t_struct *stack_a, t_struct *stack_b)
{
	t_struct	*tmp;
	t_struct	*tmp2;

	ft_printf("\n---STACK A---\n");
	while (stack_a)
	{
		ft_printf("%5d[%2d][%2d][%2d][%2d][%2d]\n", stack_a->value, stack_a->index, stack_a->pos, stack_a->target_pos, stack_a->cost_a, stack_a->cost_b);
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
	ft_printf("\n---STACK B---\n");
	while (stack_b)
	{
		ft_printf("%5d[%2d][%2d][%2d][%2d][%2d]\n", stack_b->value, stack_b->index, stack_b->pos, stack_b->target_pos, stack_b->cost_a, stack_b->cost_b);
		tmp2 = stack_b->next;
		free(stack_b);
		stack_b = tmp2;
	}
}

void print_no_free(t_struct *stack_a, t_struct *stack_b)
{
	t_struct	*tmp;
	t_struct	*tmp2;

	ft_printf("\n---STACK A---\n");
	while (stack_a)
	{
		ft_printf("%5d[%2d][%2d][%2d][%2d][%2d]\n", stack_a->value, stack_a->index, stack_a->pos, stack_a->target_pos, stack_a->cost_a, stack_a->cost_b);
		tmp = stack_a->next;
		stack_a = tmp;
	}
	ft_printf("\n---STACK B---\n");
	while (stack_b)
	{
		ft_printf("%5d[%2d][%2d][%2d][%2d][%2d]\n", stack_b->value, stack_b->index, stack_b->pos, stack_b->target_pos, stack_b->cost_a, stack_b->cost_b);
		tmp2 = stack_b->next;
		stack_b = tmp2;
	}
}