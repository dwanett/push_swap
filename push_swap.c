/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.с                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:30:06 by dwanetta          #+#    #+#             */
/*   Updated: 2021/05/16 15:30:06 by dwanetta         ###   ########.fr       */
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
	pb(&stack_a, &stack_b);
	//rra(&stack_a);
	print_stack(&stack_a);
	write(1, "\n", 1);
	print_stack(&stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}