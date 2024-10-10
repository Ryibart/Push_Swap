/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:11:56 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 13:20:45 by rtammi           ###   ########.fr       */
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
	vector_push_first(stack_a, &top);
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
	vector_push_first(stack_b, &top);
	if (flag == true)
		ft_printf("rb\n");
}

void	rrr(t_vector *stack_a, t_vector *stack_b)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	ft_printf("rrr\n");
}