/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:45:13 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 14:01:51 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_vector *stack_a, t_vector *stack_b)
{
	if (stack_a->len <= 3)
		simple_sort(stack_a);
	else
	{
		large_sort(stack_a, stack_b);
	}
	return ;
}
