/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:29:44 by rtammi            #+#    #+#             */
/*   Updated: 2024/09/30 19:07:59 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define PS_ERROR -1

void	push_swap(t_vector *stack_a, t_vector *stack_b);
void	error_handler(void);
int		verify_args(int argc, char **argv);
int		add_elements(t_vector *stack_a, int argc, char **argv);


#endif
