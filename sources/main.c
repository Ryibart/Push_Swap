/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:57:59 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/30 19:46:04 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vector	stack_a;
	t_vector	stack_b;
	int			ret;
	
	// Check for correct arguments
	verify_args(argc, argv);

	// Initialize stacks
	ret = vector_new(&stack_a, 1, sizeof(int));
	ret = vector_new(&stack_b, 1, sizeof(int));
	if (ret == VECTOR_ERROR)
		error_handler();
	
	//add elements to stack_a
	ret = add_elements(&stack_a, argc, argv);
	if (ret == PS_ERROR)
		error_handler();
	
	// Sort the stack
	push_swap(&stack_a, &stack_b);
	//free memory
	vector_free(&stack_a);
	vector_free(&stack_b);
	exit(EXIT_SUCCESS);
	
}