/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:33:31 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 16:12:35 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_vector *stack_a, t_vector *stack_b)
{
	int	element;

	if (stack_b->len == 0)
		return ;
	vector_pop_first(&element, stack_b);
	vector_push_last(stack_a, &element);
	printf("pa\n");
}

void	pb(t_vector *stack_a, t_vector *stack_b)
{
	int	element;

	if (stack_a->len == 0)
		return ;
	vector_pop_first(&element, stack_a);
	vector_push_last(stack_b, &element);
	printf("pb\n");
}
