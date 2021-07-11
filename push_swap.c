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

void test_print(t_stack **stack_a, t_stack **stack_b)
{
	print_stack(stack_a);
	print_stack(stack_b);
}

int len_stack(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		stack = stack->next;
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

int check_sort_all(t_stack *stack, int size)
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
		else if (i < size)
			return (1);
		i++;
		stack = stack->next;
	}
	if (i < size)
		return (1);
	return (0);
}

int check_sort_reverse(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;

	if (stack == NULL)
		return (0);
	tmp = stack->value;
	while (stack != NULL)
	{
		if (stack->value <= tmp)
			tmp = stack->value;
		else
			return (1);
		i++;
		stack = stack->next;
	}
	return (0);
}

int check_sort_reverse_all(t_stack *stack, int size)
{
	int tmp;
	int i;

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

int check_sort(t_stack *stack)
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
	return (0);
}

t_stack *is_valid_elem(t_stack *stack, t_stack *save)
{
	while(stack != NULL)
	{
		if (stack->flag == 0)
			return (stack);
		stack = stack->next;
	}
	return (save);
}

void serch_min_and_max(t_stack *stack, t_stack **min, t_stack **max)
{
	t_stack *tmp_min;
	t_stack *tmp_max;

	if ((*max) != NULL)
	{
		tmp_max = (*max);
		(*max) = is_valid_elem(stack, (*max));
	}
	else
		(*max) = stack;
	if ((*min) != NULL)
	{
		tmp_min = (*min);
		(*min) = is_valid_elem(stack, (*min));
	}
	else
		(*min) = stack;
	if (tmp_min == (*min) && tmp_max == (*max))
	{
		(*min) = (*max);
		return ;
	}
	while (stack != NULL)
	{
		if ((*min)->value >= stack->value && stack->flag == 0)
			(*min) = stack;
		if ((*max)->value <= stack->value && stack->flag == 0)
			(*max) = stack;
		stack = stack->next;
	}
}

int srech_mid_value(t_stack *stack)
{
	t_stack *tmp;
	t_stack *tmp_min;
	t_stack *tmp_max;

	tmp = stack;
	tmp_max = NULL;
	tmp_min = NULL;
	while (stack != NULL)
	{
		stack->flag = 0;
		stack = stack->next;
	}
	stack = tmp;
	while ((tmp_max == NULL && tmp_min == NULL) || tmp_min->value != tmp_max->value)
	{
		serch_min_and_max(stack, &tmp_min, &tmp_max);
		tmp_min->flag = 1;
		tmp_max->flag = 1;
	}
	return (tmp_min->value);
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

void sort_stack(t_stack **stack_a, t_stack **stack_b, int size, int *count)
{
	t_stack *last_elem;
	int i;

	i = check_sort_all(*stack_a, size);
	while (i == 1)
	{
		last_elem = serch_last_elem((*stack_a));
		if ((*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > last_elem->value)
		{
			ra(stack_a, 'a', count);
			if ((*stack_b)!= NULL)
				pa(stack_a, stack_b, 'a', count);
		}
		else if ((*stack_a)->next != NULL && ((*stack_a)->value > last_elem->value && ((*stack_a)->next->value > last_elem->value)))
		{
			rra(stack_a, 'a', count);
			if ((*stack_b)!= NULL)
				pa(stack_a, stack_b, 'a', count);
		}
		else if ((*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a, 'a', count);
			if ((*stack_b)!= NULL)
				pa(stack_a, stack_b, 'a', count);
		}
		else
			pb(stack_a, stack_b, 'b', count);
		i = check_sort_all(*stack_a, size);
	}
}

/*void sort_stack_a(t_stack **stack_a, t_stack **stack_b, int mid, int *count)
{
	t_stack *last_elem;
	t_stack *last_elem_b;

	last_elem = serch_last_elem((*stack_a));
	if ((*stack_b)!= NULL)
		last_elem_b = serch_last_elem((*stack_b));
	if ((*stack_a) != NULL && (*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > last_elem->value)
		ra(stack_a, 'a', count);
	else if ((*stack_a) != NULL && (*stack_a)->next != NULL && ((*stack_a)->value > last_elem->value && ((*stack_a)->next->value > last_elem->value)))
		rra(stack_a, 'a', count);
	if ((*stack_a) != NULL && (*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, 'a', count);
	else
		pb(stack_a, stack_b, 'b', count);
	if (((*stack_a) != NULL && (*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > last_elem->value)
		&& ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value && (*stack_b)->value < last_elem_b->value))
		rr(stack_a, stack_b, count);
	else if (((*stack_a) != NULL && (*stack_a)->next != NULL && ((*stack_a)->value > last_elem->value && ((*stack_a)->next->value > last_elem->value)))
			&& ((*stack_b) != NULL && (*stack_b)->next != NULL && ((*stack_b)->value < last_elem_b->value && ((*stack_b)->next->value < last_elem_b->value))))
		rrr(stack_a, stack_b, count);
	if (((*stack_a) != NULL && (*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value) && ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value))
		ss(stack_a, stack_b, count);
	else if ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value && (*stack_b)->value < last_elem_b->value)
		rb(stack_b, 'b', count);
	else if ((*stack_b) != NULL && (*stack_b)->next != NULL && ((*stack_b)->value < last_elem_b->value && ((*stack_b)->next->value < last_elem_b->value)))
		rrb(stack_b, 'b', count);
	else if ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b, 'b', count);
	if (((*stack_b) != NULL && check_sort_reverse((*stack_b)) == 0) || (*stack_a) == NULL)
	{
		while (((*stack_b) != NULL && check_sort((*stack_a)) == 0) || (*stack_a) == NULL)
			pa(stack_a, stack_b, 'a', count);
	}
}*/

void serch_min_value(t_stack *stack_a, t_stack **min)
{
	*min = NULL;
	while (stack_a != NULL)
	{
		if ((*min) == NULL || stack_a->value < (*min)->value)
			*min = stack_a;
		stack_a = stack_a->next;
	}
}

void serch_max_value(t_stack *stack_a, t_stack **max)
{
	*max = NULL;
	while (stack_a != NULL)
	{
		if ((*max) == NULL || stack_a->value > (*max)->value)
			*max = stack_a;
		stack_a = stack_a->next;
	}
}

t_stack *serch_posi_value_stack_b(t_stack *stack_a, t_stack *stack_b, int *posi)
{
	int i;
	t_stack *min;
	t_stack *max;
	t_stack *save_value;

	i = 0;
	*posi = 0;
	serch_min_value(stack_b, &min);
	serch_max_value(stack_b, &max);
	if (stack_a->value < min->value)
	{
		while (stack_b != NULL && stack_b->value >= min->value && stack_b->value != max->value)
		{
			*posi += 1;
			save_value = stack_b;
			stack_b = stack_b->next;
		}
		/*if (*posi != 0)
			*posi += 1;*/
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
			if (stack_a->value <= stack_b->value && save_value->value >= stack_b->value)
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

int count_mid_stack_b(t_stack *stack, int mid)
{
	int i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->value > mid)
			i++;
		stack = stack->next;
	}
	return (i);
}

int count_mid_stack_a(t_stack *stack, int mid)
{
	int i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->value <= mid)
			i++;
		stack = stack->next;
	}
	return (i);
}

t_stack *serch_posi_value_stack_a(t_stack *stack_a, t_stack *stack_b, int *posi_a)
{
	int i;
	t_stack *min;
	t_stack *max;
	t_stack *save_value;

	i = 0;
	*posi_a = 0;
	serch_min_value(stack_a, &min);
	serch_max_value(stack_a, &max);
	save_value = max;
	while (stack_a != NULL)
	{
		if (stack_b->value <= stack_a->value && save_value->value >= stack_a->value)
		{
			save_value = stack_a;
			*posi_a = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	if (*posi_a == 0 && save_value == max)
		return (NULL);
	return (save_value);
}

void sort_stack_big_video(t_stack **stack_a, t_stack **stack_b, int mid, int *count, int size)
{
	t_stack *min;
	int posi_b;
	int posi_a;
	int i;
	int j;
	int stack_b_size;
	int stack_a_size;
	t_stack *find_value_b;
	t_stack *find_value_a;
	t_stack *last_elem_b;

	//serch_min_value((*stack_b), &min);
	pb(stack_a, stack_b,'b', count);
	while(size != 1)
	{
		find_value_b = serch_posi_value_stack_b((*stack_a), (*stack_b), &posi_b);
		find_value_a = serch_posi_value_stack_a((*stack_a), (*stack_b), &posi_a);
		stack_b_size = len_stack((*stack_b));
		stack_a_size = len_stack((*stack_a));
		serch_min_value((*stack_b), &min);
		if (posi_b <= posi_a || (stack_b_size - posi_b) < (stack_a_size - posi_a) || find_value_b < find_value_a || find_value_a == NULL)
		{
			i = posi_b;
			while (i != 0 && i != stack_b_size)
			{
				if (stack_b_size / 2 >= posi_b)
				{
					i--;
					rb(stack_b, 'b', count);
				}
				if (stack_b_size / 2 < posi_b)
				{
					i++;
					rrb(stack_b, 'b', count);
				}
				//test_print(stack_a, stack_b);
			}
			pb(stack_a, stack_b, 'b', count);
			last_elem_b = serch_last_elem((*stack_b));
		}
		else
		{
			j = posi_a;
			find_value_b = serch_posi_value_stack_b(find_value_a, (*stack_b), &posi_b);
			if (posi_b != 0 && posi_b != stack_b_size)
			{
				i = posi_b;
				while (j != 0 && j != stack_a_size || i != 0 && i != stack_b_size)
				{
					if ((stack_a_size / 2 >= posi_a) && (stack_b_size / 2 >= posi_b) && j != 0 && i != 0)
					{
						j--;
						i--;
						rr(stack_a, stack_b, count);
					}
					else if (stack_a_size / 2 >= posi_a && j != 0)
					{
						j--;
						ra(stack_a, 'a', count);
					}
					else if (stack_b_size / 2 >= posi_b && i != 0)
					{
						i--;
						rb(stack_b, 'b', count);
					}
					if ((stack_a_size / 2 < posi_a) && (stack_b_size / 2 < posi_b) && j != stack_a_size && i != stack_b_size)
					{
						j++;
						i++;
						rrr(stack_a, stack_b, count);
					}
					else if (stack_a_size / 2 < posi_a && j != stack_a_size)
					{
						j++;
						rra(stack_a, 'a', count);
					}
					else if (stack_b_size / 2 < posi_b && i != stack_b_size)
					{
						i++;
						rrb(stack_b, 'b', count);
					}
					//test_print(stack_a, stack_b);
				}
			}
			else
			{
				while (j != 0 && j != stack_a_size)
				{
					if (stack_a_size / 2 >= posi_a)
					{
						j--;
						ra(stack_a, 'a', count);
					}
					if (stack_a_size / 2 < posi_a)
					{
						j++;
						rra(stack_a, 'a', count);
					}
					//test_print(stack_a, stack_b);
				}
			}
			//test_print(stack_a, stack_b);
			pb(stack_a, stack_b, 'b', count);
		}
		size--;
		//test_print(stack_a, stack_b);
	}
}

void rotate_stack_b(t_stack **stack_b, int size, int *count)
{
	t_stack *max;
	t_stack *tmp;
	int i;

	serch_max_value((*stack_b), &max);
	tmp = (*stack_b);
	i = 0;
	while ((*stack_b) != NULL)
	{
		if ((*stack_b) == max)
			break;
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

void help_sort_stack_b(t_stack **stack_b, int *count)
{
	t_stack *last_elem;
	int i;

	last_elem = serch_last_elem((*stack_b));
	i = 1;
	while (i != 0)
	{
		if ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value &&
			(*stack_b)->value < last_elem->value)
			rb(stack_b, 'b', count);
		else if ((*stack_b) != NULL && (*stack_b)->next != NULL &&
				 ((*stack_b)->value < last_elem->value && ((*stack_b)->next->value < last_elem->value)))
			rrb(stack_b, 'b', count);
		else if ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b, 'b', count);
		i = check_sort_reverse_all((*stack_b), 3);
	}
}

void init_info(t_stack **stack_a)
{
	(*stack_a)->info.ra = 0;
	(*stack_a)->info.rb = 0;
	(*stack_a)->info.rr = 0;
	(*stack_a)->info.rra = 0;
	(*stack_a)->info.rrb = 0;
	(*stack_a)->info.rrr = 0;
	(*stack_a)->info.sum = 0;
}

void count_iter_for_elem(t_stack **stack_a, t_stack **stack_b)
{
	int posi_b;
	t_stack *tmp;
	int len_b;
	int len_a;
	int i;

	len_b = len_stack((*stack_b));
	len_a  = len_stack((*stack_a));
	i = 0;
	tmp = (*stack_a);
	while ((*stack_a) != NULL)
	{
		serch_posi_value_stack_b((*stack_a), (*stack_b), &posi_b);
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
		(*stack_a)->info.sum = (*stack_a)->info.rb + (*stack_a)->info.rrb + (*stack_a)->info.ra + (*stack_a)->info.rra + (*stack_a)->info.rr + (*stack_a)->info.rrr;
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = tmp;
}

void serch_need_value(t_stack *stack_a, t_stack **need_value)
{
	(*need_value) = NULL;
	while (stack_a != NULL)
	{
		if ((*need_value) == NULL || stack_a->info.sum < (*need_value)->info.sum)
			(*need_value) = stack_a;
		stack_a = stack_a->next;
	}
}

void sort_stack_b(t_stack **stack_a, t_stack **stack_b, int *count, int size)
{
	int i;
	t_stack *need_value;

	i = 0;
	while(i != 3)
	{
		pb(stack_a, stack_b, 'b', count);
		i++;
	}
	help_sort_stack_b(stack_b, count);
	while ((*stack_a) != NULL)
	{
		count_iter_for_elem(stack_a, stack_b);
		serch_need_value((*stack_a), &need_value);
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
		size--;
	}
}
void sort_big_stack(t_stack **stack_a, t_stack **stack_b, int size, int *count)
{
	int mid;

	mid = srech_mid_value((*stack_a));
	printf("mid = %d\n", mid);
	sort_stack_b(stack_a, stack_b, count, size);
	test_print(stack_a, stack_b);
	rotate_stack_b(stack_b, size, count);
	while ((*stack_b) != NULL)
		pa(stack_a, stack_b, 'a', count);
	test_print(stack_a, stack_b);
	printf("count = %d\n", *count);
	exit(0);
}

int main(int ac, char *av[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	int count;

	stack_a = NULL;
	stack_b = NULL;
	count = 0;
	if (ac == 1)
		error_print(2);
	create_stack(&stack_a, ac ,av);
	check_stack_repeat_num(stack_a);
	/*if (ac <= 4 && ac != 2)
		sort_three_elem(&stack_a, ac - 1);*/
	print_stack(&stack_a);
	if (ac <= 5)
		sort_stack(&stack_a, &stack_b, ac - 1, &count);
	else
		sort_big_stack(&stack_a, &stack_b, ac - 1, &count);
	print_stack(&stack_a);
	print_stack(&stack_b);
	printf("count = %d\n", count);
	printf("size_stack = %d\n", ac -1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}