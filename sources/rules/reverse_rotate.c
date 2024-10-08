/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:11:56 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 20:04:19 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_vector *stack_a, bool flag)
{
	int	top;

	top = 0;
	if (stack_a->len < 2)
		return ;
	vector_pop_last(&top, stack_a);
	printf("Rotating: Popped %d from stack_a\n", top);
	vector_push_first(stack_a, &top);
	printf("Rotating: Pushed %d back to stack_a\n", top);
	if (flag == true)
		ft_printf("ra\n");
}
void	rrb(t_vector *stack_b, bool flag)
{
	int	top;

	top = 0;
	if (stack_b->len < 2)
		return ;
	vector_pop_last(&top, stack_b);
	printf("Rotating: Popped %d from stack_b\n", top);
	vector_push_first(stack_b, &top);
	printf("Rotating: Pushed %d back to stack_b\n", top);
	if (flag == true)
		ft_printf("rb\n");
}

void	rrr(t_vector *stack_a, t_vector *stack_b)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	ft_printf("rrr\n");
}