/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:57:59 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 13:41:26 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int(void *elem)
{
	ft_printf("%d ", *(int *)elem);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (verify_args(argc, argv) == PS_ERROR)
		error_handler(NULL, NULL);
	vector_new(&ps.stack_a, 1, sizeof(int));
	vector_new(&ps.stack_b, 1, sizeof(int));
	if (add_elements(&ps.stack_a, argc, argv) == PS_ERROR)
		error_handler(&ps.stack_a, &ps.stack_b);
	if (check_duplicates(&ps.stack_a) == PS_ERROR)
		error_handler(&ps.stack_a, &ps.stack_b);
	push_swap(&ps.stack_a, &ps.stack_b);
	vector_iter(&ps.stack_a, print_int); // debug
	ft_printf("\n");
	vector_free(&ps.stack_a);
	vector_free(&ps.stack_b);
	exit(EXIT_SUCCESS);
}
