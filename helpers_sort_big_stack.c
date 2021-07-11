/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_sort_big_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 01:42:22 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/12 01:42:22 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_help_sort_stack_b(t_stack **stack_a, t_stack **stack_b,
							int *count, t_stack **need_value)
{
	while ((*need_value)->info.rra != 0)
	{
		rra(stack_a, 'a', count);
		(*need_value)->info.rra--;
	}
	while ((*need_value)->info.rb != 0)
	{
		rb(stack_b, 'b', count);
		(*need_value)->info.rb--;
	}
	while ((*need_value)->info.rrb != 0)
	{
		rrb(stack_b, 'b', count);
		(*need_value)->info.rrb--;
	}
}

void	help_sort_stack_b(t_stack **stack_a, t_stack **stack_b,
					   int *count, t_stack **need_value)
{
	while ((*need_value)->info.rr != 0)
	{
		rr(stack_a, stack_b, count);
		(*need_value)->info.rr--;
	}
	while ((*need_value)->info.rrr != 0)
	{
		rrr(stack_a, stack_b, count);
		(*need_value)->info.rrr--;
	}
	while ((*need_value)->info.ra != 0)
	{
		ra(stack_a, 'a', count);
		(*need_value)->info.ra--;
	}
	help_help_sort_stack_b(stack_a, stack_b, count, need_value);
}

void	help_count_iter_for_elem(t_stack **stack_a)
{
	while ((*stack_a)->info.ra != 0 && (*stack_a)->info.rb != 0)
	{
		(*stack_a)->info.ra--;
		(*stack_a)->info.rb--;
		(*stack_a)->info.rr++;
	}
	while ((*stack_a)->info.rra != 0 && (*stack_a)->info.rrb != 0)
	{
		(*stack_a)->info.rra--;
		(*stack_a)->info.rrb--;
		(*stack_a)->info.rrr++;
	}
	(*stack_a)->info.sum = (*stack_a)->info.rb + (*stack_a)->info.rrb
		+ (*stack_a)->info.ra + (*stack_a)->info.rra
		+ (*stack_a)->info.rr + (*stack_a)->info.rrr;
}

void	help_search_posi_val_stack_b(t_stack *stack_a, t_stack *stack_b,
			t_stack *max, int *posi)
{
	t_stack	*save_value;
	int		i;

	i = 0;
	save_value = max;
	while (stack_b != NULL)
	{
		if (stack_a->value <= stack_b->value
			&& save_value->value >= stack_b->value)
		{
			save_value = stack_b;
			*posi = i;
		}
		i++;
		stack_b = stack_b->next;
	}
	*posi += 1;
}
