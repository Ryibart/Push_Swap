/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:34:11 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 16:12:51 by rtammi           ###   ########.fr       */
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
	printf("Rotating: Popped %d from stack_a\n", top);
	vector_push_last(stack_a, &top);
	printf("Rotating: Pushed %d back to stack_a\n", top);
	if (flag == true)
		ft_printf("ra\n");
}

void	rb(t_vector *stack_b, bool flag)
{
	int	*top;

	top = 0;
	if (stack_b->len < 2)
		return ;
	top = (int *)vector_get(stack_b, stack_b->len - 1);
	vector_push_last(stack_b, &top);
	if (flag == true)
		ft_printf("rb\n");
}

void	rr(t_vector *stack_a, t_vector *stack_b)
{
	ra(stack_a, false);
	rb(stack_b, false);
	ft_printf("rr\n");
}
