/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:56:59 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 13:59:01 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_intcmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

int check_duplicates(t_vector *stack)
{
	t_vector	tmp;
	size_t		i;
	size_t		j;
	
	vector_new(&tmp, stack->len, sizeof(int));
	vector_copy(&tmp, stack);
	vector_sort(&tmp, &ft_intcmp);
	i = 0;
	while (i < tmp.len)
	{
		j = i + 1;
		while (j < tmp.len)
		{
			if (*(int *)vector_get(&tmp, i) == *(int *)vector_get(&tmp, j))
			{
				vector_free(&tmp);
				return (PS_ERROR);
			}
			j++;
		}
		i++;
	}
	vector_free(&tmp);
	return (PS_SUCCESS);
}
	