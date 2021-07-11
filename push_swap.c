/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:30:06 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/10 17:30:51 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if ((*stack_a) != NULL)
	{
		while ((*stack_a)->next != NULL)
		{
			ft_putnbr_fd((*stack_a)->value, 1);
			ft_putstr_fd(" ", 1);
			*stack_a = (*stack_a)->next;
		}
		ft_putnbr_fd((*stack_a)->value, 1);
		*stack_a = tmp;
		write(1, "\n", 1);
	}
}

void	test_print(t_stack **stack_a, t_stack **stack_b)
{
	print_stack(stack_a);
	print_stack(stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size, int *count)
{
	t_stack	*last_elem;
	int		i;

	i = check_sort_all(*stack_a, size);
	while (i == 1)
	{
		last_elem = search_last_elem((*stack_a));
		if ((*stack_a)->next != NULL
			&& (*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->value > last_elem->value)
		{
			ra(stack_a, 'a', count);
			if ((*stack_b) != NULL)
				pa(stack_a, stack_b, 'a', count);
		}
		else if ((*stack_a)->next != NULL
			&& ((*stack_a)->value > last_elem->value
				&& ((*stack_a)->next->value > last_elem->value)))
		{
			rra(stack_a, 'a', count);
			if ((*stack_b) != NULL)
				pa(stack_a, stack_b, 'a', count);
		}
		else if ((*stack_a)->next != NULL
			&& (*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a, 'a', count);
			if ((*stack_b) != NULL)
				pa(stack_a, stack_b, 'a', count);
		}
		else
			pb(stack_a, stack_b, 'b', count);
		i = check_sort_all(*stack_a, size);
	}
}

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

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;

	stack_a = NULL;
	stack_b = NULL;
	count = 0;
	if (ac == 1)
		error_print(2);
	create_stack(&stack_a, ac, av);
	check_stack_repeat_num(stack_a);
	if (ac - 1 <= 4)
		sort_stack(&stack_a, &stack_b, ac - 1, &count);
	else if (ac - 1 <= 6)
		printf("size_stack = %d\n", ac - 1);
	else
		sort_big_stack(&stack_a, &stack_b, ac - 1, &count);
	test_print(&stack_a, &stack_b);
	printf("count = %d\n", count);
	printf("size_stack = %d\n", ac - 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
