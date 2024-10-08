/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:33:24 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 14:22:26 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_vector *stack_a, bool flag)
{
	int	temp;

	if (stack_a->len < 2)
		return ;
	temp = *(int *)vector_get(stack_a, 0);
	*(int *)vector_get(stack_a, 0) = *(int *)vector_get(stack_a, 1);
	*(int *)vector_get(stack_a, 1) = temp;
	if (flag == true)
		ft_printf("sa\n");
}

void	sb(t_vector *stack_b, bool flag)
{
	long	temp;

	if (stack_b->len < 2)
		return ;
	temp = *(int *)vector_get(stack_b, 0);
	*(int *)vector_get(stack_b, 0) = *(int *)vector_get(stack_b, 1);
	*(int *)vector_get(stack_b, 1) = temp;
	if (flag == true)
		ft_printf("sb\n");
}

void	ss(t_vector *stack_a, t_vector *stack_b)
{
	if (stack_a->len < 2)
		return ;
	sa(stack_a, false);
	sb(stack_b, false);
	ft_printf("ss\n");
}
