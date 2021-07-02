/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/02 21:43:26 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack **stack_a, char c)
{
	t_stack *new_last;
	t_stack *tmp;

	tmp = (*stack_a);
	if ((*stack_a) != NULL && (*stack_a)->next != NULL)
	{
		while ((*stack_a)->next != NULL)
		{
			if ((*stack_a)->next->next == NULL)
				new_last = (*stack_a);
			(*stack_a) = (*stack_a)->next;
		}
		(*stack_a)->next = tmp;
		new_last->next = NULL;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
}

void rrb(t_stack **stack_b, char c)
{
	rra(stack_b, c);
	write(1, "rrb\n", 4);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 'a');
	rrb(stack_b, 'b');
}
