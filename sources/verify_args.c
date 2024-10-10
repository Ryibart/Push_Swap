/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:21:14 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/09 14:10:39 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (PS_ERROR);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (argc == 2 && (ft_isspace(argv[i][j]) || argv[i][j] == '-' || argv[i][j] == '+')) //FIXTHIS: Correct the parsing logic
					j++;
				else
					return (PS_ERROR);
			}
			j++;
		}
		i++;
	}
	return (1);
}
