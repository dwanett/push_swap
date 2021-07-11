/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/11 15:24:25 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, char c, int *count)
{
	t_stack	*ferst;
	t_stack	*tmp;

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
	if (c == 'a')
		write(1, "ra\n", 3);
	*count += 1;
}

void	rb(t_stack **stack_b, char c, int *count)
{
	ra(stack_b, c, count);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int *count)
{
	ra(stack_a, 'r', count);
	rb(stack_b, 'r', count);
	*count -= 1;
	write(1, "rr\n", 3);
}
