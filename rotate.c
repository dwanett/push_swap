/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/06/27 18:45:27 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **stack_a)
{
	t_stack *ferst;
	t_stack *tmp;

	ferst = (*stack_a);
	if ((*stack_a) != NULL && (*stack_a)->next != NULL)
	{
		(*stack_a) = (*stack_a)->next;
		tmp = (*stack_a);
		while ((*stack_a)->next != NULL)
			(*stack_a) = (*stack_a)->next;
		(*stack_a)->next = ferst;
		(*stack_a)->next->next = NULL;
		(*stack_a) = tmp;
	}
}

void rb(t_stack **stack_b)
{
	ra(stack_b);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}