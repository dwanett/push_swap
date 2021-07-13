/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:55:08 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/13 17:35:51 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
		i++;
	return (i);
}

void	chek_argv_int(char *arg)
{
	int		len;
	char	*max_int;
	char	*min_int;
	int		i;

	len = ft_strlen(arg);
	i = 0;
	max_int = "2147483647";
	min_int = "-2147483648";
	if (len == 10)
	{
		while (arg[i] <= max_int[i] && i != len)
			i++;
	}
	if (len == 11)
	{
		while (arg[i] <= min_int[i] && i != len)
			i++;
	}
	if (i != 0 && i < len)
		error_print(6);
}

int	create_stack_for_arg(t_stack **stack_a, char *av[])
{
	t_stack	*tmp;
	char	**arg;
	int		ac;
	int		i;

	tmp = NULL;
	arg = ft_split(av[1], ' ');
	ac = len_arg(arg);
	i = ac;
	i--;
	while (i >= 0)
	{
		*stack_a = (t_stack *) malloc(sizeof(t_stack));
		if (*stack_a == NULL)
			error_print(4);
		if (check_arg_num(arg[i]) == 0)
			error_print(3);
		chek_argv_int(arg[i]);
		(*stack_a)->value = ft_atoi(arg[i]);
		(*stack_a)->next = tmp;
		tmp = *stack_a;
		i--;
	}
	return (ac);
}
