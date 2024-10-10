/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:52 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 12:19:49 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_string(t_vector *stack_a, char **argv)
{
	char	**tmp;
	int		i;
	long	element;
	int		valid;

	i = 0;
	tmp = ft_split(argv[1], 32);
	// while (tmp[i])
	// {
	// 	printf("tmp[%d] is : %s\n", i, tmp[i]); // DEBUG
	// 	i++;
	// }
	i = 0;
	while (tmp[i])
	{
		element = ft_strtol(tmp[i], NULL, 10, &valid);
		// printf("Element %d is %ld\n", i, element); // DEBUG
		if (!valid || element < INT_MIN || element > INT_MAX)
		{
			free(tmp);
			return (PS_ERROR);
		}
		vector_push_last(stack_a, (int *)&element);
		i++;
	}
	i--;
	while (i >= 0)
		free(tmp[i--]);
	free(tmp);
	return (1);
}

int	add_elements(t_vector *stack_a, int argc, char **argv)
{
	int		i;
	long	num;
	int		valid;

	i = 1;
	if (argc == 2)
	{
		if (split_string(stack_a, argv) == PS_ERROR)
			return (PS_ERROR);
	}
	else
	{
		while (i < argc)
		{
			num = ft_strtol(argv[i], NULL, 10, &valid);
			// printf("num is %ld\n", num);
			if (!valid || num < INT_MIN || num > INT_MAX)
				return (PS_ERROR);
			vector_push_last(stack_a, &num);
			// for (size_t j = 0; j < stack_a->len; j++) //DEBUG
  			// {
    		// 	printf("Element %ld: %d\n", j, *((int *)vector_get(stack_a, j)));
			// }
			i++;
		}
	}
	return (1);
}