/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:57:59 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 19:52:16 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int(void *elem)
{
	printf("%d ", *(int *)elem);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	verify_args(argc, argv);
	vector_new(&ps.stack_a, 1, sizeof(int));
	vector_new(&ps.stack_b, 1, sizeof(int));
	if (add_elements(&ps.stack_a, argc, argv) == PS_ERROR)
		error_handler();
	push_swap(&ps.stack_a, &ps.stack_b);
	vector_iter(&ps.stack_a, print_int); // debug
	vector_free(&ps.stack_a);
	vector_free(&ps.stack_b);
	exit(EXIT_SUCCESS);
}
