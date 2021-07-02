/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:30:06 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/02 19:35:46 by dwanetta         ###   ########.fr       */
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

void sort_three_elem(t_stack **stack, int size)
{
	if (size == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
		{
			sa(stack);
			write(1, "sa\n", 3);
		}
	}
	else
	{
		if (((*stack)->value > (*stack)->next->value && (*stack)->value < (*stack)->next->next->value) ||
		((*stack)->value < (*stack)->next->value && (*stack)->next->next->value < (*stack)->next->value && (*stack)->value < (*stack)->next->next->value) ||
		((*stack)->value > (*stack)->next->value && (*stack)->next->value > (*stack)->next->next->value))
		{
			sa(stack);
			write(1, "sa\n", 3);
		}
		if ((*stack)->next->next->value < (*stack)->value && (*stack)->next->next->value < (*stack)->next->value)
		{
			rra(stack);
			write(1, "rra\n", 4);
		}
		if ((*stack)->next->value < (*stack)->value && (*stack)->next->next->value > (*stack)->next->value)
		{
			ra(stack);
			write(1, "ra\n", 3);
		}
	}
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
	if (ac <= 4 && ac != 2)
		sort_three_elem(&stack_a, ac - 1);
	print_stack(&stack_a);
	write(1, "\n", 1);
	print_stack(&stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
