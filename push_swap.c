/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:30:06 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/12 20:05:50 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b,
			int size, int *count)
{
	int	i;

	i = check_sort_all(*stack_a, size);
	if (i == 1)
	{
		sort_stack_b(stack_a, stack_b, count);
		rotate_stack_b(stack_b, size, count);
		while ((*stack_b) != NULL)
			pa(stack_a, stack_b, 'a', count);
	}
}

void	sort_small_stack(t_stack **stack_a, int *count, int size)
{
	t_stack	*last_elem;
	int		i;

	last_elem = search_last_elem((*stack_a));
	i = check_sort_all((*stack_a), size);
	while (i == 1)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			ra(stack_a, 'a', count);
		else if ((*stack_a)->next->value > last_elem->value)
			rra(stack_a, 'a', count);
		i = check_sort_all((*stack_a), size);
		if (i == 1)
			sa(stack_a, 'a', count);
		i = check_sort_all((*stack_a), size);
	}
}

void	sort_middle_stack(t_stack **stack_a,
			t_stack **stack_b, int size, int *count)
{
	int		stop;

	if (size <= 3)
	{
		sort_small_stack(stack_a, count, size);
		return ;
	}
	if (size == 4)
		stop = 1;
	if (size == 5)
		stop = 2;
	if (size == 6)
		stop = 3;
	help_sort_middle_stack(stack_a, stack_b, stop, count);
	sort_small_stack(stack_a, count, size - stop);
	while ((*stack_b) != NULL)
		pa(stack_a, stack_b, 'a', count);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	count = 0;
	if (ac == 1)
		error_print(2);
	if (ac == 2)
		ac = create_stack_for_arg(&stack_a, av) + 1;
	else
		create_stack(&stack_a, ac, av);
	check_stack_repeat_num(stack_a);
	i = check_sort_all(stack_a, ac - 1);
	if (i == 1)
	{
		if (ac - 1 <= 6)
			sort_middle_stack(&stack_a, &stack_b, ac - 1, &count);
		else
			sort_big_stack(&stack_a, &stack_b, ac - 1, &count);
	}
	free_stack(&stack_a);
	return (0);
}
