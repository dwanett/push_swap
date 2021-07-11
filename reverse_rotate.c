/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/11 15:24:02 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, char c, int *count)
{
	t_stack	*new_last;
	t_stack	*tmp;

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
	*count += 1;
}

void	rrb(t_stack **stack_b, char c, int *count)
{
	rra(stack_b, c, count);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int *count)
{
	rra(stack_a, 'r', count);
	rrb(stack_b, 'r', count);
	*count -= 1;
	write(1, "rrr\n", 4);
}
