/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:32:42 by dwanetta          #+#    #+#             */
/*   Updated: 2021/07/02 21:39:21 by dwanetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct	s_stack
{
	int					value;
	int					flag;
	struct s_stack		*next;
}						t_stack;


void			error_print(int code);
void			free_stack(t_stack **stack_a);
int				check_arg_num(char *agr);
void			check_stack_repeat_num(t_stack *stack_a);
void			create_stack(t_stack **stack_a, int ac, char *av[]);
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
