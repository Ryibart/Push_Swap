/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:34:11 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 13:20:33 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_vector *stack_a, bool flag)
{
	int	top;

	top = 0;
	if (stack_a->len < 2)
		return ;
	vector_pop_first(&top, stack_a);
	vector_push_last(stack_a, &top);
	if (flag == true)
		ft_printf("ra\n");
}

void	rb(t_vector *stack_b, bool flag)
{
	int	top;

	top = 0;
	if (stack_b->len < 2)
		return ;
	vector_pop_first(&top, stack_b);
	vector_push_last(stack_b, &top);
	if (flag == true)
		ft_printf("ra\n");
}

void	rr(t_vector *stack_a, t_vector *stack_b)
{
	ra(stack_a, false);
	rb(stack_b, false);
	ft_printf("rr\n");
}
