/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/11 15:26:35 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*search_last_elem(t_stack *stack)
{
	if (stack != NULL)
	{
		while (stack->next != NULL)
			stack = stack->next;
	}
	return (stack);
}

void	search_min_value(t_stack *stack_a, t_stack **min)
{
	*min = NULL;
	while (stack_a != NULL)
	{
		if ((*min) == NULL || stack_a->value < (*min)->value)
			*min = stack_a;
		stack_a = stack_a->next;
	}
}

void	search_max_value(t_stack *stack_a, t_stack **max)
{
	*max = NULL;
	while (stack_a != NULL)
	{
		if ((*max) == NULL || stack_a->value > (*max)->value)
			*max = stack_a;
		stack_a = stack_a->next;
	}
}

void	search_need_value(t_stack *stack_a, t_stack **need_value)
{
	(*need_value) = NULL;
	while (stack_a != NULL)
	{
		if ((*need_value) == NULL
			|| stack_a->info.sum < (*need_value)->info.sum)
			(*need_value) = stack_a;
		stack_a = stack_a->next;
	}
}
