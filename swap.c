/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/02 21:38:29 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **stack_a, char c)
{
	t_stack *tmp;

	tmp = (*stack_a);
	if ((*stack_a) != NULL && (*stack_a)->next != NULL)
	{
		(*stack_a) = (*stack_a)->next;
		tmp->next = (*stack_a)->next;
		(*stack_a)->next = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
}

void sb(t_stack **stack_b, char c)
{
	sa(stack_b, c);
	write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 'a');
	sb(stack_b, 'b');
}
