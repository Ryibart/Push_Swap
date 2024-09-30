/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:52 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/30 19:45:39 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int split_string(t_vector *stack_a, char **argv)
{
	char	**tmp;
	int		i;
	int		element;
	int		valid;

	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		element = ft_strtol(tmp[i], NULL, 10, &valid);
		if (!valid)
			return (PS_ERROR);
		vector_push(stack_a, &element);
		i++;
	}
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
			if (!valid)
				return (PS_ERROR);
			vector_push(stack_a, &num);
			i++;
		}
	}
	return (1);
}