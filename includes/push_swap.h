/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:29:44 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 16:11:51 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define PS_ERROR -1
# define PS_OK 0
# define PS_SUCCESS 1

typedef struct s_push_swap
{
	t_vector	stack_a;
	t_vector	stack_b;
}				t_push_swap;

void	push_swap(t_vector *stack_a, t_vector *stack_b);
void	error_handler(void);
int		verify_args(int argc, char **argv);
int		add_elements(t_vector *stack_a, int argc, char **argv);

void	pa(t_vector *stack_a, t_vector *stack_b);
void	pb(t_vector *stack_a, t_vector *stack_b);
void	sa(t_vector *stack_a, bool flag);
void	sb(t_vector *stack_b, bool flag);
void	ss(t_vector *stack_a, t_vector *stack_b);
void	ra(t_vector *stack_a, bool flag);
void	rb(t_vector *stack_b, bool flag);
void	rr(t_vector *stack_a, t_vector *stack_b);
void	rra(t_vector *stack_a, bool flag);

void	print_stack(t_vector *stack, char stack_name);

#endif
