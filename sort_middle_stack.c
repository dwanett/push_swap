/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:59:59 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/12 00:59:59 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_iter_stack_a(t_stack *stack_a, t_stack *min)
{
	int	i;

	i = 0;
	while (stack_a != min)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void	help_help_sort_middle_stack(t_stack **stack_a, int size,
			int i, int *count)
{
	int		posi_a;
	t_stack	*min;

	search_min_value((*stack_a), &min);
	posi_a = count_iter_stack_a((*stack_a), min);
	if (size / 2 >= posi_a)
	{
		while (posi_a != 0)
		{
			ra(stack_a, 'a', count);
			posi_a--;
		}
	}
	else if (size / 2 < posi_a)
	{
		while (posi_a != size - i)
		{
			rra(stack_a, 'a', count);
			posi_a++;
		}
	}
}

void	help_sort_middle_stack(t_stack **stack_a,
			t_stack **stack_b, int stop, int *count)
{
	int	i;
	int	size;

	i = 0;
	size = len_stack((*stack_a));
	while (i != stop)
	{
		help_help_sort_middle_stack(stack_a, size, i, count);
		pb(stack_a, stack_b, 'b', count);
		i++;
	}
}
