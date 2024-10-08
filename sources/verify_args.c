/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:21:14 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/07 16:19:31 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		error_handler();
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
					error_handler();
			}
			j++;
		}
		i++;
	}
	return (1);
}
