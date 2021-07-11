/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_check_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:39:53 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/11 15:22:53 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg_num(char *agr)
{
	int	ret;
	int	i;

	ret = 1;
	i = 0;
	while (agr[i] != '\0')
	{
		ret = ft_isdigit(agr[i]);
		if (ret == 0 && agr[i] != '-')
			break ;
		i++;
	}
	return (ret);
}

void	check_stack_repeat_num(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack_a;
	while (tmp != NULL)
	{
		tmp2 = stack_a;
		while (tmp2 != NULL)
		{
			if (tmp != tmp2 && tmp->value == tmp2->value)
				error_print(5);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	create_stack(t_stack **stack_a, int ac, char *av[])
{
	t_stack	*tmp;

	tmp = NULL;
	ac--;
	while (ac != 0)
	{
		*stack_a = (t_stack *) malloc(sizeof(t_stack));
		if (*stack_a == NULL)
			error_print(4);
		if (check_arg_num(av[ac]) == 0)
			error_print(3);
		(*stack_a)->value = ft_atoi(av[ac]);
		(*stack_a)->next = tmp;
		tmp = *stack_a;
		ac--;
	}
}

int	check_sort_all(t_stack *stack, int size)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack == NULL)
		return (1);
	tmp = stack->value;
	while (stack != NULL)
	{
		if (stack->value >= tmp)
			tmp = stack->value;
		else if (i < size)
			return (1);
		i++;
		stack = stack->next;
	}
	if (i < size)
		return (1);
	return (0);
}

int	check_sort_reverse_all(t_stack *stack, int size)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack == NULL)
		return (1);
	tmp = stack->value;
	while (stack != NULL)
	{
		if (stack->value <= tmp)
			tmp = stack->value;
		else if (i < size)
			return (1);
		i++;
		stack = stack->next;
	}
	if (i < size)
		return (1);
	return (0);
}
