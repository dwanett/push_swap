/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/02 21:44:18 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack *tmp;

	tmp = (*stack_b);
	if ((*stack_b) != NULL)
	{
		(*stack_b) = (*stack_b)->next;
		tmp->next = (*stack_a);
		(*stack_a) = tmp;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
}

void pb(t_stack **stack_a, t_stack **stack_b, char c)
{
	pa(stack_b, stack_a, c);
	write(1, "pb\n", 3);
}
