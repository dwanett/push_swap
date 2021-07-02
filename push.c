/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/06/27 18:45:15 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	tmp = (*stack_b);
	if ((*stack_b) != NULL)
	{
		(*stack_b) = (*stack_b)->next;
		tmp->next = (*stack_a);
		(*stack_a) = tmp;
	}
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	pa(stack_b, stack_a);
}