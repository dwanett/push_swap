/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:32:42 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/13 17:40:14 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_count_step
{
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					sum;
}						t_count_step;

typedef struct s_stack
{
	int					value;
	t_count_step		info;
	struct s_stack		*next;
}						t_stack;

void			error_print(int code);
void			free_stack(t_stack **stack_a);
int				check_arg_num(char *agr);
void			init_info(t_stack **stack_a);
void			check_stack_repeat_num(t_stack *stack_a);
void			create_stack(t_stack **stack_a, int ac, char *av[]);
int				len_stack(t_stack *stack);
int				check_sort_all(t_stack *stack, int size);
int				check_sort_reverse_all(t_stack *stack, int size);
t_stack			*search_last_elem(t_stack *stack);
void			search_min_value(t_stack *stack_a, t_stack **min);
void			search_max_value(t_stack *stack_a, t_stack **max);
void			search_need_value(t_stack *stack_a, t_stack **need_value);
void			search_posi_val_stack_b(t_stack *stack_a,
					t_stack *stack_b, int *posi);
void			rotate_stack_b(t_stack **stack_b, int size, int *count);
void			sort_stack_b(t_stack **stack_a, t_stack **stack_b, int *count);
void			help_sort_stack_b(t_stack **stack_a, t_stack **stack_b,
					int *count, t_stack **need_value);
void			help_count_iter_for_elem(t_stack **stack_a);
int				count_iter_stack_a(t_stack *stack_a, t_stack *min);
void			help_helcount_iter_for_elemp_sort_middle_stack(
					t_stack **stack_a, int size, int i, int *count);
void			help_search_posi_val_stack_b(t_stack *stack_a,
					t_stack *stack_b, t_stack *max, int *posi);
void			help_sort_middle_stack(t_stack **stack_a, t_stack **stack_b,
					int stop, int *count);
int				len_arg(char **arg);
void			chek_argv_int(char *arg);
int				create_stack_for_arg(t_stack **stack_a, char *av[]);
void			pa(t_stack **stack_a, t_stack **stack_b, char c, int *count);
void			pb(t_stack **stack_a, t_stack **stack_b, char c, int *count);
void			sa(t_stack **stack_a, char c, int *count);
void			sb(t_stack **stack_a, char c, int *count);
void			ss(t_stack **stack_a, t_stack **stack_b, int *count);
void			ra(t_stack **stack_a, char c, int *count);
void			rb(t_stack **stack_a, char c, int *count);
void			rr(t_stack **stack_a, t_stack **stack_b, int *count);
void			rra(t_stack **stack_a, char c, int *count);
void			rrb(t_stack **stack_a, char c, int *count);
void			rrr(t_stack **stack_a, t_stack **stack_b, int *count);
#endif
