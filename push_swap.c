/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:30:06 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/05 03:06:52 by dwanetta         ###   ########.fr       */
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
		while (stack_b != NULL && stack_b->value > min->value && stack_b->value != max->value)
		{
			*posi += 1;
			save_value = stack_b;
			stack_b = stack_b->next;
		}
		if (*posi != 0)
			*posi += 1;
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

/*void del_stack(t_stack **stack_a, t_stack **stack_b, int mid, int *count)
{
	t_stack *min;
	t_stack *last_elem_a;
	t_stack *last_elem_b;
	int i;
	int mid_cnt;

	serch_min_value((*stack_a), &min);
	mid_cnt = 0;
	while (min->value <= mid)
	{
		i = 0;
		while ((*stack_a)->value != min->value)
		{
			last_elem_a = serch_last_elem((*stack_a));
			if ((*stack_a) != NULL && (*stack_a)->next != NULL && ((*stack_a)->value > last_elem_a->value && ((*stack_a)->next->value > last_elem_a->value)))
				rra(stack_a, 'a', count);
			else if ((*stack_a) != NULL && (*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > last_elem_a->value)
				ra(stack_a, 'a', count);
			//test_print(stack_a, stack_b);
			if ((*stack_a) != NULL && (*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a, 'a', count);
			else if ((*stack_a)->value != min->value)
			{
				pb(stack_a, stack_b, 'b', count);
				i++;
			}
			//write(1, "tut1\n", 5);
			//test_print(stack_a, stack_b);
		}
		pb(stack_a, stack_b, 'b', count);
		if (i != 0)
		{
			rb(stack_b, 'b', count);
			mid_cnt = count_mid_stack_b((*stack_b), mid);
		}
		test_print(stack_a, stack_b);
		printf("count = %d\n", *count);
		//exit(0);
		while (mid_cnt != 0)
		{
			last_elem_b = serch_last_elem((*stack_b));
			if ((*stack_b)->value > mid)
				pa(stack_a, stack_b, 'a', count);
			if ((*stack_b) != NULL && (*stack_b)->next != NULL && ((*stack_b)->value < last_elem_b->value && ((*stack_b)->next->value < last_elem_b->value)))
				rrb(stack_b, 'b', count);
			else if ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value && (*stack_b)->value < last_elem_b->value)
				rb(stack_b, 'b', count);
			//test_print(stack_a, stack_b);
			else if (mid_cnt > 0)
				rrb(stack_b, 'b', count);
			if ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value)
				sb(stack_b, 'b', count);
			if ((*stack_b)->value > mid)
				pa(stack_a, stack_b, 'a', count);
			mid_cnt = count_mid_stack_b((*stack_b) , mid);
			//test_print(stack_a, stack_b);
			//write(1, "tut2\n", 5);
		}
		//printf("count = %d\n", *count);
		if (count_mid_stack_b((*stack_b), mid) == 0 && count_mid_stack_a((*stack_a), mid) == 0)
			break ;
		serch_min_value((*stack_a), &min);
		//test_print(stack_a, stack_b);
		//printf("count = %d\n", *count);
		//exit(0);
	}
}*/

/*
void sort_satck_and_conect(t_stack **stack_a, t_stack **stack_b, int *count)
{
	int is_sort_a;
	int is_sort_b;
	t_stack *last_elem_a;
	t_stack *last_elem_b;
	int i;
	t_stack *max;

	is_sort_a = check_sort((*stack_a));
	is_sort_b = check_sort_reverse((*stack_b));
	i = 0;

	while (is_sort_a && is_sort_b)
	{
		while (is_sort_a)
		{
			last_elem_a = serch_last_elem((*stack_a));
			if ((*stack_a) != NULL && (*stack_a)->next != NULL && ((*stack_a)->value > last_elem_a->value && ((*stack_a)->next->value > last_elem_a->value)))
				rra(stack_a, 'a', count);
			else if ((*stack_a) != NULL && (*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > last_elem_a->value)
				ra(stack_a, 'a', count);
			//test_print(stack_a, stack_b);
			if ((*stack_a) != NULL && (*stack_a)->next != NULL && (*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a, 'a', count);
			is_sort_a = check_sort((*stack_a));
			if (is_sort_a)
			{
				i++;
				//write(1, "sort_a\n", 7);
				pb(stack_a, stack_b, 'b', count);
			}
			//test_print(stack_a, stack_b);
		}
		//test_print(stack_a, stack_b);
		//printf("count = %d\n", *count);
		//exit(0);
		while (i != 0)
		{
			pa(stack_a, stack_b, 'a', count);
			i--;
		}
		is_sort_a = check_sort((*stack_a));
		while (is_sort_b && is_sort_a == 0)
		{
			if ((*stack_b)->value == max->value && is_sort_a == 0)
				pa(stack_a, stack_b, 'a', count);
			else if ((*stack_b) != NULL && (*stack_b)->next != NULL && ((*stack_b)->value < last_elem_b->value && ((*stack_b)->next->value < last_elem_b->value)))
				rrb(stack_b, 'b', count);
			else if ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value && (*stack_b)->value < last_elem_b->value)
				rb(stack_b, 'b', count);
			else if ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < (*stack_b)->next->value)
				sb(stack_b, 'b', count);
			else
			{
				i++;
				pa(stack_a, stack_b, 'a', count);
			}
			serch_max_value((*stack_b), &max);
			//test_print(stack_a, stack_b);
			is_sort_b = check_sort_reverse((*stack_b));
		}
		while (i != 0)
		{
			pb(stack_a, stack_b, 'b', count);
			i--;
		}
		is_sort_b = check_sort_reverse((*stack_b));
	}
	while ((*stack_b) != NULL)
		pa(stack_a, stack_b, 'a', count);
}
*/
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
	int is_sort_b;
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
	is_sort_b = 1;
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
		test_print(stack_a, stack_b);
	}
	while ((*stack_b) != NULL && (*stack_b)->next != NULL && (*stack_b)->value < last_elem_b->value)
		rb(stack_b, 'b', count);
	//rb(stack_b, 'b', count);
	test_print(stack_a, stack_b);
	printf("count = %d\n", *count);
	exit(0);
}

void sort_big_stack(t_stack **stack_a, t_stack **stack_b, int size, int *count)
{
	int i;
	int mid;

	i = check_sort_all(*stack_a, size);
	mid = srech_mid_value((*stack_a));
	printf("mid = %d\n", mid);
	while (i == 1)
	{
		//sort_stack_a(stack_a, stack_b, mid, count);
		//del_stack(stack_a, stack_b, mid, count)
		sort_stack_big_video(stack_a, stack_b, mid, count, size);
		//test_print(stack_a, stack_b);
		//printf("count = %d\n", *count);
		//exit(0);
		//sort_satck_and_conect(stack_a, stack_b, count);
		i = check_sort_all(*stack_a, size);
		//exit(0);
	}
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


//100-500 size_stack_a / 12;
//10-100 size_stack_a / 4;
//0-10 size_stack_a / 2;

//value < mid