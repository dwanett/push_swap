/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:08:53 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/11 16:08:53 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_posi_val_stack_b(t_stack *stack_a, t_stack *stack_b, int *posi)
{
	t_stack	*min;
	t_stack	*max;

	*posi = 0;
	search_min_value(stack_b, &min);
	search_max_value(stack_b, &max);
	if (stack_a->value < min->value)
	{
		while (stack_b != NULL && stack_b->value >= min->value
			&& stack_b->value != max->value)
		{
			*posi += 1;
			stack_b = stack_b->next;
		}
	}
	else if (stack_a->value > max->value)
	{
		while (stack_b != NULL && stack_b->value < max->value)
		{
			*posi += 1;
			stack_b = stack_b->next;
		}
	}
	else
		help_search_posi_val_stack_b(stack_a, stack_b, max, posi);
}

void	rotate_stack_b(t_stack **stack_b, int size, int *count)
{
	t_stack	*max;
	t_stack	*tmp;
	int		i;

	search_max_value((*stack_b), &max);
	tmp = (*stack_b);
	i = 0;
	while ((*stack_b) != NULL)
	{
		if ((*stack_b) == max)
			break ;
		i++;
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = tmp;
	if (i < size / 2)
	{
		while ((*stack_b) != max)
			rb(stack_b, 'b', count);
	}
	else
	{
		while ((*stack_b) != max)
			rrb(stack_b, 'b', count);
	}
}

void	small_sort_stack_b(t_stack **stack_b, int *count, int size)
{
	t_stack	*last_elem;
	int		i;

	last_elem = search_last_elem((*stack_b));
	i = check_sort_reverse_all((*stack_b), size);
	while (i == 1)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
			rb(stack_b, 'b', count);
		else if ((*stack_b)->next->value < last_elem->value)
			rrb(stack_b, 'b', count);
		i = check_sort_reverse_all((*stack_b), size);
		if (i == 1)
			sb(stack_b, 'b', count);
		i = check_sort_reverse_all((*stack_b), size);
	}
}

void	count_iter_for_elem(t_stack **stack_a, t_stack **stack_b,
			int len_a, int len_b)
{
	t_stack	*tmp;
	int		posi_b;
	int		i;

	i = 0;
	tmp = (*stack_a);
	while ((*stack_a) != NULL)
	{
		init_info(stack_a);
		search_posi_val_stack_b((*stack_a), (*stack_b), &posi_b);
		if (len_b / 2 >= posi_b)
			(*stack_a)->info.rb = posi_b;
		if (len_b / 2 < posi_b)
			(*stack_a)->info.rrb = len_b - posi_b;
		if (len_a / 2 >= i)
			(*stack_a)->info.ra = i;
		if (len_a / 2 < i)
			(*stack_a)->info.rra = len_a - i;
		help_count_iter_for_elem(stack_a);
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	(*stack_a) = tmp;
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b, int *count)
{
	t_stack	*need_value;
	int		i;
	int		len_a;
	int		len_b;

	i = 0;
	while (i != 3)
	{
		pb(stack_a, stack_b, 'b', count);
		i++;
	}
	small_sort_stack_b(stack_b, count, i);
	while ((*stack_a) != NULL)
	{
		len_b = len_stack((*stack_b));
		len_a = len_stack((*stack_a));
		count_iter_for_elem(stack_a, stack_b, len_a, len_b);
		search_need_value((*stack_a), &need_value);
		help_sort_stack_b(stack_a, stack_b, count, &need_value);
		pb(stack_a, stack_b, 'b', count);
	}
}
