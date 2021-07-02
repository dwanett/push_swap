/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/06/27 18:45:31 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **stack_a)
{
	t_stack *tmp;

	tmp = (*stack_a);
	if ((*stack_a) != NULL && (*stack_a)->next != NULL)
	{
		(*stack_a) = (*stack_a)->next;
		tmp->next = (*stack_a)->next;
		(*stack_a)->next = tmp;
	}
}

void sb(t_stack **stack_b)
{
	sa(stack_b);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}