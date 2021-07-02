/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:36:38 by dwanetta          #+#    #+#             */
/*   Updated: 2021/06/27 18:45:40 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_print(int code)
{
	ft_putstr_fd("Error: ", 2);
	if (code == 2)
		ft_putstr_fd("Invalid number of arguments\n", 2);
	if (code == 3)
		ft_putstr_fd("The set of numbers must be integer\n", 2);
	if (code == 4)
		ft_putstr_fd("Memory\n", 2);
	if (code == 5)
		ft_putstr_fd("duplicate characters\n", 2);
	exit(code);
}

void free_stack(t_stack **stack_a)
{
	t_stack *tmp;

	if ((*stack_a) != NULL)
	{
		while ((*stack_a)->next != NULL)
		{
			tmp = *stack_a;
			*stack_a = (*stack_a)->next;
			free(tmp);
		}
		free(*stack_a);
	}
}