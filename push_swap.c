/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:30:06 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/04 00:47:34 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack **stack_a)
{
	t_stack *tmp;

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

int len_stack(t_stack *stack_a)
{
	int	len;

	len = 0;
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		len++;
	}
	return (len);
}
/*
void sort_three_elem(t_stack **stack, int size)
{
	if (size == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
		{
			sa(stack, 'a');
		}
	}
	else
	{
		if (((*stack)->value > (*stack)->next->value && (*stack)->value < (*stack)->next->next->value) ||
		((*stack)->value < (*stack)->next->value && (*stack)->next->next->value < (*stack)->next->value && (*stack)->value < (*stack)->next->next->value) ||
		((*stack)->value > (*stack)->next->value && (*stack)->next->value > (*stack)->next->next->value))
		{
			sa(stack, 'a');
		}
		if ((*stack)->next->next->value < (*stack)->value && (*stack)->next->next->value < (*stack)->next->value)
		{
			rra(stack, 'a');
		}
		if ((*stack)->next->value < (*stack)->value && (*stack)->next->next->value > (*stack)->next->value)
		{
			ra(stack, 'a');
		}
	}
}
*/

int check_sort(t_stack *stack, int size)
{
	int tmp;
	int i;

	i = 0;

	if (stack == NULL)
		return (1);
	tmp = stack->value;
	while (stack != NULL)
	{
		if (stack->value >= tmp)
			tmp = stack->value;
		else
			return (1);
		i++;
		stack = stack->next;
	}
	if (i < size)
		return (i);
	return (0);
}

t_stack *serch_last_elem(t_stack *stack)
{
	if (stack != NULL)
	{
		while (stack->next != NULL)
			stack = stack->next;
	}
	return (stack);
}

void sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack *last_elem;
	int i;

	i = check_sort(*stack_a, size);
	while (i == 1)
	{
		last_elem = serch_last_elem((*stack_a));
		if ((*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > last_elem->value)
		{
			ra(stack_a, 'a');
			if ((*stack_b)!= NULL)
				pa(stack_a, stack_b, 'a');
		}
		else if ((*stack_a)->next != NULL && ((*stack_a)->value > last_elem->value && ((*stack_a)->next->value > last_elem->value)))
		{
			rra(stack_a, 'a');
			if ((*stack_b)!= NULL)
				pa(stack_a, stack_b, 'a');
		}
		else if ((*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a, 'a');
			if ((*stack_b)!= NULL)
				pa(stack_a, stack_b, 'a');
		}
		else
			pb(stack_a, stack_b, 'b');
		i = check_sort(*stack_a, size);
		//print_stack(stack_a);

	}
	if (i > 1 && i != size)
	{
		pa(stack_a, stack_b, 'a');
		//print_stack(stack_a);
		sort_stack(stack_a, stack_b, size);
	}
}

void sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{

}

void sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{

}

int srech_mid_value(t_stack *stack, int size)
{
	t_stack *tmp;
	t_stack *tmp_min;
	t_stack *tmp_max;
	int min;
	int max;
	int i;

	tmp = stack;
	min = stack->value;
	max = stack->value;
	i = 0;
	tmp_min = stack;
	tmp_max = stack;
	while (stack != NULL)
	{
		stack->flag = 0;
		stack = stack->next;
	}
	stack = tmp;
	while (i != 5 /*|| (tmp_min->value != tmp_max->value)*/)
	{
		while (stack != NULL)
		{
			if (tmp_min->value >= stack->value && stack->flag == 0)
				tmp_min = stack;
			else if (stack->next->next == NULL && stack->next->flag == 1)
			{
				tmp_min = stack;
				break ;
			}
			stack = stack->next;
		}
		tmp_min->flag = 1;
		stack = tmp;
		min = stack->value;
		/*while (stack != NULL)
		{
			if (max >= stack->value)
			{
				if (tmp_max != NULL)
					tmp_max->flag = 0;
				tmp_max = stack;
				stack->flag = 1;
				max = stack->value;
			}
			stack = stack->next;
		}*/
		//stack = tmp;
		i++;
		printf("min = %d\n", min);
		printf("max = %d\n", max);
	}
}

void sort_big_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack *last_elem;
	int i;

	i = check_sort(*stack_a, size);
	srech_mid_value((*stack_a), size);
	//while (i == 1)
	//{
		//sort_stack_a(stack_a, stack_b);
		//sort_stack_b(stack_a, stack_b);
		//i = check_sort(*stack_a, size);
	//}
}

int main(int ac, char *av[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		error_print(2);
	create_stack(&stack_a, ac ,av);
	check_stack_repeat_num(stack_a);
	/*if (ac <= 4 && ac != 2)
		sort_three_elem(&stack_a, ac - 1);*/
	if (ac <= 5)
		sort_stack(&stack_a, &stack_b, ac - 1);
	else
		sort_big_stack(&stack_a, &stack_b, ac - 1);
	print_stack(&stack_a);
	print_stack(&stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
