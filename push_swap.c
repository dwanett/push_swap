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

int count_iter_stack_a(t_stack *stack_a, t_stack *min)
{
	int i;

	i = 0;
	while (stack_a != min)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void	sort_middle_stack(t_stack **stack_a, t_stack **stack_b, int size, int *count)
{
	int i;
	int stop;
	int posi_a;
	t_stack *min;

	i = 0;
	if (size == 3)
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
	while (i != stop)
	{
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
		pb(stack_a, stack_b, 'b',count);
		i++;
	}
	sort_small_stack(stack_a, count, size - stop);
	while ((*stack_b) != NULL)
		pa(stack_a, stack_b, 'a',count);
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
	i = 0;
	if (ac == 1)
		error_print(2);
	create_stack(&stack_a, ac, av);
	check_stack_repeat_num(stack_a);
	i = check_sort_all(stack_a, ac - 1);
	if (i == 1)
	{
		if (ac - 1 <= 6)
			sort_middle_stack(&stack_a, &stack_b, ac - 1, &count);
		else
			sort_big_stack(&stack_a, &stack_b, ac - 1, &count);
		//test_print(&stack_a, &stack_b);
		//printf("count = %d\n", count);
		//printf("size_stack = %d\n", ac - 1);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
