/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:57:59 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/02 14:14:29 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_long(void *elem)
{
	printf("%ld ", *(long *)elem);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_vector	stack_a;
	t_vector	stack_b;
	int			ret;
	
	// Check for correct arguments
	verify_args(argc, argv);

	// Initialize stacks
	ret = vector_new(&stack_a, 1, sizeof(long));
	ret = vector_new(&stack_b, 1, sizeof(long));
	if (ret == VECTOR_ERROR)
		error_handler();
	
	//add elements to stack_a
	ret = add_elements(&stack_a, argc, argv);
	if (ret == PS_ERROR)
		error_handler();
	
	// Sort the stack
	push_swap(&stack_a, &stack_b);
	vector_iter(&stack_a, print_long);
	//free memory
	vector_free(&stack_a);
	vector_free(&stack_b);
	exit(EXIT_SUCCESS);
	
}