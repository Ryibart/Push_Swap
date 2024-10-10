/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:30:04 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/09 14:08:35 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(t_vector *stack_a, t_vector *stack_b)
{
	if (stack_a)
		vector_free(stack_a);
	if (stack_b)
		vector_free(stack_b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
