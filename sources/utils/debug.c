/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:36:23 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 14:29:28 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_vector *stack, char stack_name)
{
	printf("Stack %c: ", stack_name);
	for (size_t i = 0; i < stack->len; i++)
	{
		int *elem = (int *)vector_get(stack, i);
		printf("%d ", *elem);
	}
	printf("\n");
}