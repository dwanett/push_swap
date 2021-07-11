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
	}
	write(1, "\n", 1);
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

t_stack	*search_posi_val_stack_b(t_stack *stack_a, t_stack *stack_b, int *posi)
{
	int		i;
	t_stack	*min;
	t_stack	*max;
	t_stack	*save_value;

	i = 0;
	*posi = 0;
	search_min_value(stack_b, &min);
	search_max_value(stack_b, &max);
	if (stack_a->value < min->value)
	{
		while (stack_b != NULL && stack_b->value >= min->value
			&& stack_b->value != max->value)
		{
			*posi += 1;
			save_value = stack_b;
			stack_b = stack_b->next;
		}
	}
	else if (stack_a->value > max->value)
	{
		while (stack_b != NULL && stack_b->value < max->value)
		{
			*posi += 1;
			save_value = stack_b;
			stack_b = stack_b->next;
		}
	}
	else
	{
		save_value = max;
		while (stack_b != NULL)
		{
			if (stack_a->value <= stack_b->value
				&& save_value->value >= stack_b->value)
			{
				save_value = stack_b;
				*posi = i;
			}
			i++;
			stack_b = stack_b->next;
		}
		*posi += 1;
	}
	return (save_value);
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

void	help_sort_stack_b(t_stack **stack_b, int *count, int size)
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

void	count_iter_for_elem(t_stack **stack_a, t_stack **stack_b)
{
	int		posi_b;
	t_stack	*tmp;
	int		len_b;
	int		len_a;
	int		i;

	len_b = len_stack((*stack_b));
	len_a = len_stack((*stack_a));
	i = 0;
	tmp = (*stack_a);
	while ((*stack_a) != NULL)
	{
		search_posi_val_stack_b((*stack_a), (*stack_b), &posi_b);
		init_info(stack_a);
		if (len_b / 2 >= posi_b)
			(*stack_a)->info.rb = posi_b;
		if (len_b / 2 < posi_b)
			(*stack_a)->info.rrb = len_b - posi_b;
		if (len_a / 2 >= i)
			(*stack_a)->info.ra = i;
		if (len_a / 2 < i)
			(*stack_a)->info.rra = len_a - i;
		while ((*stack_a)->info.ra != 0 && (*stack_a)->info.rb != 0)
		{
			(*stack_a)->info.ra--;
			(*stack_a)->info.rb--;
			(*stack_a)->info.rr++;
		}
		while ((*stack_a)->info.rra != 0 && (*stack_a)->info.rrb != 0)
		{
			(*stack_a)->info.rra--;
			(*stack_a)->info.rrb--;
			(*stack_a)->info.rrr++;
		}
		i++;
		(*stack_a)->info.sum = (*stack_a)->info.rb + (*stack_a)->info.rrb
			+ (*stack_a)->info.ra + (*stack_a)->info.rra
			+ (*stack_a)->info.rr + (*stack_a)->info.rrr;
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = tmp;
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b, int *count, int size)
{
	int		i;
	t_stack	*need_value;

	i = 0;
	while (i != 3)
	{
		pb(stack_a, stack_b, 'b', count);
		i++;
	}
	help_sort_stack_b(stack_b, count, i);
	i = check_sort_all(*stack_a, size - i);
	while ((*stack_a) != NULL && i == 1)
	{
		count_iter_for_elem(stack_a, stack_b);
		search_need_value((*stack_a), &need_value);
		while (need_value->info.rr != 0)
		{
			rr(stack_a, stack_b, count);
			need_value->info.rr--;
		}
		while (need_value->info.rrr != 0)
		{
			rrr(stack_a, stack_b, count);
			need_value->info.rrr--;
		}
		while (need_value->info.ra != 0)
		{
			ra(stack_a, 'a', count);
			need_value->info.ra--;
		}
		while (need_value->info.rra != 0)
		{
			rra(stack_a, 'a', count);
			need_value->info.rra--;
		}
		while (need_value->info.rb != 0)
		{
			rb(stack_b, 'b', count);
			need_value->info.rb--;
		}
		while (need_value->info.rrb != 0)
		{
			rrb(stack_b, 'b', count);
			need_value->info.rrb--;
		}
		pb(stack_a, stack_b, 'b', count);
	}
}

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b,
			int size, int *count)
{
	int	i;

	i = check_sort_all(*stack_a, size);
	if (i == 1)
	{
		sort_stack_b(stack_a, stack_b, count, size);
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
	if (ac <= 5)
		sort_stack(&stack_a, &stack_b, ac - 1, &count);
	else
		sort_big_stack(&stack_a, &stack_b, ac - 1, &count);
	test_print(&stack_a, &stack_b);
	printf("count = %d\n", count);
	printf("size_stack = %d\n", ac -1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
